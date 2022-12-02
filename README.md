# 五子棋

## 总体框架

1. 能下棋，放置棋子并进行展示
   1. 棋子：位置，棋手，顺序
   2. 棋盘：大小棋子二维数组，路径
   3. 展示：控制台输出，GUI交互。

2. 能够进行胜负判断（可选禁手）

   1. 简单胜利判断（五连子）：朴素遍历，深度优先，广度优先，KMP匹配

   2. 禁手判断：KMP

      

3. ~~网络交互~~

   1. Qt：QtNetwork/QTcpSocket/QTcpServer

   2. 控制台：winsock/winsok2

      

4. 用户图形接口（GUI）
   1. ~~Qt： GUI-Qt Version 5.15~~
   
   2. easyx
      1. 首页显示模式信息（PVP PVE）与其余基本信息
      
      2. 一：PVP选择禁手与无禁手  二：PVE做无禁手
      
      3. 棋盘界面，点击下棋，做悔棋功能
      
      4. 棋盘的落点：25开始，每格约40
      
         


mx:25   my:26
mx:25   my:26
mx:25   my:26
mx:67   my:61
mx:67   my:61
mx:67   my:61
mx:67   my:61
mx:107  my:101
mx:149  my:146
mx:190  my:186
mx:190  my:186
mx:231  my:226
mx:231  my:226
mx:231  my:226
mx:231  my:226
mx:231  my:226
mx:231  my:226
mx:272  my:267
mx:272  my:267
mx:272  my:267
mx:272  my:267
mx:272  my:267
mx:315  my:307
mx:315  my:307
mx:352  my:348
mx:352  my:348
mx:352  my:348
mx:352  my:348
mx:396  my:391
mx:396  my:391
mx:396  my:391
mx:396  my:391
mx:396  my:391
mx:437  my:432
mx:437  my:432
mx:437  my:432
mx:481  my:475
mx:521  my:515
mx:521  my:515
mx:521  my:515
mx:521  my:515
mx:521  my:515
mx:562  my:557
mx:562  my:557
mx:562  my:557
mx:606  my:599
mx:606  my:599
mx:606  my:599
mx:647  my:639
mx:647  my:639
mx:647  my:639
mx:647  my:639
mx:647  my:639
mx:691  my:679
mx:691  my:679
mx:691  my:679
mx:691  my:679
mx:691  my:679
mx:729  my:720
mx:729  my:720
mx:767  my:765
mx:767  my:765
mx:767  my:765
mx:767  my:765
mx:767  my:765
mx:767  my:765