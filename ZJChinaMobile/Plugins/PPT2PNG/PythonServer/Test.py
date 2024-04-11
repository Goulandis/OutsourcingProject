import ppt2gif

#这里输入ppt文件路径，使用双斜杠（\\）
ppt_file = "D:/Goulandis/EdgeDonwload/1-240330151101"
ppt_obj = ppt2gif.PPT( ppt_file )
ppt_obj.convert2png()