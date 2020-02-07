# 游戏简介
<br/>  《肺村战疫》是一款新型冠状病毒背景下的公益塔防游戏，使用Unreal Engine4.24.2开发。希望能在这场冠状病毒战役中能让大家放松下心情。
<br/>  肺村抵御蝙蝠病毒攻击，共9波蝙蝠从起点骷髅位置沿着地图道路抵达肺村，并进行攻击，肺村受到伤害由红色逐渐变白。玩家通过金币购买并放置炮台到地图中，炮台自动攻击到达攻击范围内的蝙蝠。当9波蝙蝠都消灭后游戏胜利。肺村完全变白游戏失败。

# 项目安装
<br/>1.需要先安装Unreal Engine4.24.2 及以上版本
<br/>2.需要安装Visual Stuido 2015以上版本
<br/>3.切换分支为dev
<br/>4.点击Clone or download，点击Download ZIP
<br/>5.解压下载好的Zip包nCoVTowerDefense-dev.zip
<br/>6.右键nCoVTowerDefense.uproject文件选择Switch Unreal Engine version，选择Unreal Engine4.24.2 及以上版本
<br/>7.右键nCoVTowerDefense.uproject文件选择Generate Visual Studio project files，完成后文件夹会生成一些文件
<br/>8.找到nCoVTowerDefense.sln用Visual Stuido打开编译运行即可

# 道具介绍
<br/>蝙蝠
<br/>攻击方式：敌人沿着路线到肺村，抵达后发出冠状病毒子弹攻击肺部
<br/>炮台
<br/>攻击方式：监测到蝙蝠到攻击范围后发出药丸子弹攻击蝙蝠
<br/>攻击范围：4米
<br/>肺村
<br/>攻击方式：当蝙蝠到达肺村范围后免疫细胞主动攻击蝙蝠
# 游戏流程
运行游戏-点击play-播放过场镜头动画-蝙蝠沿路线到肺村飞行-鼠标点击场景中炮坑购买放置炮台-炮台攻击蝙蝠-蝙蝠死亡获得50金币-蝙蝠到达肺村攻击肺村-肺村发出免疫细胞攻击蝙蝠-9轮蝙蝠-游戏判定胜负
# 胜负判定
<br/>胜利条件：9波蝙蝠都消灭
<br/>失败条件：肺村完全变白
# 金币系统
<br/>初始金币：200
<br/>炮台价值100
<br/>蝙蝠死亡获得50
# 伤害系统
<br/>蝙蝠血量：第一波300
<br/>肺村血量：10000
<br/>炮台攻击力：10
<br/>蝙蝠攻击力:100
<br/>肺村免疫细胞攻击力：60

# 参考图
![image](https://raw.githubusercontent.com/sheencity/nCoVTowerDefense/dev/Picture/Pic01.jpg)
![image](https://raw.githubusercontent.com/sheencity/nCoVTowerDefense/dev/Picture/Pic02.jpg)
![image](https://raw.githubusercontent.com/sheencity/nCoVTowerDefense/dev/Picture/Pic03.jpg)

# 寄语
只要相信 一切终将雨过天晴 中国加油!!!

