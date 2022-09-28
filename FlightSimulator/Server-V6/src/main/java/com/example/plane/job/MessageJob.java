package com.example.plane.job;

import com.alibaba.fastjson.JSON;
import com.csvreader.CsvReader;
import com.example.plane.enety.Plane;
import com.example.plane.service.WsService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.Charset;
import java.util.Objects;

import static com.sun.javafx.scene.control.skin.Utils.getResource;
//import static com.sun.org.apache.xerces.internal.utils.SecuritySupport.getResourceAsStream;


/**
 * 消息生成job
 */
@Slf4j
@Service
@EnableScheduling
public class MessageJob {
    @Autowired
    WsService wsService;

    private InputStream resourceAsStream   ;

    private CsvReader csvReader ;

    private  int count = 1;

   {
       log.info(String.valueOf(MessageJob.class.getResource("/450second.csv")));
//       resourceAsStream  = getResourceAsStream("./testData.csv");
       try {
//           resourceAsStream  = MessageJob.class.getResource("/reuser.csv").openStream();
           resourceAsStream  = Objects.requireNonNull(MessageJob.class.getResource("/450second.csv")).openStream();
       } catch (IOException e) {
           throw new RuntimeException(e);
       }
       if(resourceAsStream !=null){
           csvReader = new CsvReader(resourceAsStream, ',', Charset.forName("UTF-8"));
           log.info("csvReader 创建成功");
           try {
               csvReader.readHeaders();
           } catch (IOException e) {
               throw new RuntimeException(e);
           }
       }
       else {
           System.out.println("resourceAsStream NULL! ");
       }


   }

    /**
     * 每1s发送
     */

    // 如果你的文件没有表头，这行不用执行
    // 这行不要是为了从表头的下一行读，也就是过滤表头

//    @Scheduled(cron = "0/1 * * * * *")
    @Scheduled(fixedRate = 200)
    public void run(){
        try {
            //通过这种方式发送数据 读取数据

//
//            // 如果你的文件没有表头，这行不用执行
//            // 这行不要是为了从表头的下一行读，也就是过滤表头
//            csvReader.readHeaders();
//            log.info("开始发送数据\n");
            // 读取每行的内容

            if(csvReader !=null) {
                log.info("定时任务执行");

                csvReader.readRecord();


                Plane plane = new Plane();
                try {
                    csvReader.get(0);
                    plane.setPlaneID(Float.parseFloat(csvReader.get(0)));
                    plane.setLatitude(Float.parseFloat(csvReader.get(1)));
                    plane.setLongitude(Float.parseFloat(csvReader.get(2)));
                    plane.setGeoAltitude(Float.parseFloat(csvReader.get(3)));
                    plane.setPitchAngle(Float.parseFloat(csvReader.get(4)));
                    plane.setDirectionAngle(Float.parseFloat(csvReader.get(5)));

                    wsService.broadcastMsg(JSON.toJSONString(plane));
                    log.info("调用wsService发送 数据");
                }
                catch (Exception e ){
                    log.info("数据发送完成");

                    e.printStackTrace();

                }


            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
