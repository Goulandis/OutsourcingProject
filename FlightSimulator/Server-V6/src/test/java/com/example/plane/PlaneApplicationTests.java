package com.example.plane;

import com.csvreader.CsvReader;
import com.opencsv.CSVReader;
import com.opencsv.exceptions.CsvValidationException;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

@SpringBootTest
class PlaneApplicationTests {

    @Test
    void contextLoads() {

        String fileName ="D:\\Java\\plane\\src\\main\\resources\\res.csv";
        try (BufferedReader file = new BufferedReader(new InputStreamReader(new FileInputStream(fileName), "UTF-8"))) {
            String record;
            while ((record = file.readLine()) != null) {
                System.out.println(record);
                String[] cells = record.split(",");
                for (String cell : cells) {
                    System.out.println(cell);
                }
            }
        } catch (Exception e) {

        }
    }

    @Test
    void readCsv(){
        try (Reader reader = Files.newBufferedReader(Paths.get("D:\\Java\\plane\\src\\main\\resources\\res.csv"));
             CSVReader csvReader = new CSVReader(reader)) {

            String[] record;
            while ((record = csvReader.readNext()) != null) {
//                System.out.println("User["+ String.join(", ", record) +"]");
                System.out.println(String.join(", ", record));
            }

        } catch (IOException | CsvValidationException ex) {
            ex.printStackTrace();
            throw new RuntimeException(ex);
        }
    }
    @Test
    void testRead() throws IOException {

            // 第一参数：读取文件的路径 第二个参数：分隔符（不懂仔细查看引用百度百科的那段话） 第三个参数：字符集
            CsvReader csvReader = new CsvReader("D:\\Java\\plane\\src\\main\\resources\\res.csv", ',', Charset.forName("UTF-8"));

            // 如果你的文件没有表头，这行不用执行
            // 这行不要是为了从表头的下一行读，也就是过滤表头
            csvReader.readHeaders();

            // 读取每行的内容
            while (csvReader.readRecord()) {
                // 获取内容的两种方式
                // 1. 通过下标获取
                System.out.println(csvReader.get(1));

            }

    }
}
