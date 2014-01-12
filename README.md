MagicTower
======================
powered by QT 5.2.0

项目概述
----------
* 按21层版本魔塔地图制作；
* 丰富多彩的图形和小动画；
* 集成全部原版音效；
* 完整的地图加载和存档功能；
* 较完备的轻量级地图编辑；
* 扩展和改编简单易行。

开发环境
----------
* 基于QT 5.2.0的QMainWindow(Core GUI)和QT多媒体库QMultiMedia环境，以及最新的C++11编译器；
* 2D绘图、文字绘制均使用QPainter，配合QTimer发送重画信号，形成动画；
* 输入事件主要为键盘，可触发或相应游戏中的相关事件。该事件由继承了QMainWindow的MainWindow类发出。


开发技术
----------
* 充分利用C++的面向对象特点，过程和对象几乎完全封装于类中，并且充分利用类继承的多态特性，在触发事件、对象重画、获取对象属性等方面都起到了至关重要的作用。另外构造函数的继承方式非常有助于批量设置同类项对象属性，同时避免代码重复(Don't repeat your self)和犯低级错误的问题。
* 脚本语言的语法解释和脚本语言的元编程(Metaprogramming)特性。魔塔程序具有解释固定语法的文本地图文件的能力，支持以下功能

> * C语言的基本运算符

        +, -, *, /, %, ^, &, <<, >>, ~, =, <, <=, >, >=, ==, !=

> * if分支结构，和goto跳转

        i = 0
        :for_i
        i = i + 1
        if (i <= 3)
            goto for_i

> * 对象的属性获取与设置

        tom->health = 10000
        emeny_3->attack = 300
        
> * 像CSS选择器一样好用的对象选择功能

        .hidden->enabled = 0
        wall.hidden
        #axe->pix = ":/images/axe"

> * 对象事件触发（主角经过时生效）

        on (.fragile)
        {
            this->enabled = 0
        }
        
        on (#merchant_exp)
        {
            input("You can use your extra exp to grow your power, please choose: ", "1. 50 exp -> 10 attack", "2. 30 exp -> 7 defend", "3. 100 exp -> {15 attack, 15 defend}", "4. Not this time.")
            if (input == 1)
                if (tom->exp >= 50)
                {
                    tom->exp = tom->exp - 50
                    tom->attack = tom->attack + 10
                }
            if (input == 2)
                if (tom->exp >= 30)
                {
                    tom->exp = tom->exp - 30
                    tom->defend = tom->defend + 7
                }
            if (input == 3)
                if (tom->exp >= 100)
                {
                    tom->exp = tom->exp - 100
                    tom->attack = tom->attack + 15
                    tom->defend = tom->defend + 15
                }
        }
        
        
