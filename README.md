# 五子棋

## 总体框架

1. 能下棋，放置棋子并进行展示
   1. 棋子：位置，棋手，顺序
   2. 棋盘：大小棋子二维数组，路径
   3. 展示：~~控制台输出~~（调试过程中），GUI交互。

2. 能够进行胜负判断（可选禁手）

   1. 胜利判断（五连子）：~~朴素遍历，深度优先，广度优先，~~KMP匹配

   2. 禁手判断（先去学规则）：KMP

      

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
      
      5. 页面？
      
         1. 主页
      
         2. switch模式（PVP）
      
         3. 下棋界面
      
            
      
         

5. 模式？
   1. PVP禁手加业余
   2. PVE~~禁手~~加业余
   3. EVE业余

## AI

1. 实现总体框架？
   1. kmp导入读取四个方向的棋子
   2. 格子赋分
   3. 调参数（自己成为五子棋专家bushi）
   4. EVE?黑白分开基本抄一遍之前做的就行了。
   
   

# github仓库

[for4WARD/2022_autumn_final_work: 计导五子棋小游戏 (github.com)](https://github.com/for4WARD/2022_autumn_final_work)