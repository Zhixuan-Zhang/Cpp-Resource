# 黑马程序员C++教程改进代码
## 说明
黑马程序员的C++课程对于新手入门C++非常友好，但是项目代码的写法依然具有提升空间，因此我也在一边跟着做项目一边阅读[《C++ Primer》](https://item.jd.com/11306138.html)，[《Effective C++》](https://item.jd.com/10393318.html)等书籍。以及一些有用的在线资源例如[Google 开源项目风格指南](https://zh-google-styleguide.readthedocs.io/en/latest/contents/), [Google Test](https://google.github.io/googletest/) 我试着学习他们的风格重写了最后两个项目，但由于时间有限，里面依然存在很多不足，后期如果有时间的话我也会修复它们，争取给大家做一个模板项目。大部分函数和视频中完全一样，只是修改了写法，尽量降低冗余。 如果觉得有帮助的话记得点亮小星星呦。
## B站链接
[黑马程序员匠心之作|C++教程从0到1入门编程,学习编程不再难](https://www.bilibili.com/video/BV1et411b73Z)

## 编译方法

进入其中一个文件夹后，在Terminal输入：
~~~
mkdir build
cd build
cmake ../
make
./main
~~~
正常的话就可以进入到程序了

## 改进方面
1. 命名空间： cout->std::cout [关于 using namespace std](https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice)
2. 封装：将相同操作封装成一个模板函数
3. 使用C++11 新特性，使代码变得简洁，例如：for(auto it:vStu){...}
4. 使用CMakelist，提升跨平台编译能力。本人使用的工具链是GNU+CLion

## TODO
1. 第二个项目还没有完全完成，不过基础框架已经有了
2. 变量命名不规范，需要后期改进
3. 代码冗余较多，还需后期优化。
4. 后期可以绘制UML，让大家进一步理解软件工程。这里推荐两本书[《Software Engineering》](https://www.oreilly.com/library/view/software-engineering-10th/9780137586691/)和[《UML Distilled Standard Modeling Language》](https://www.amazon.ca/UML-Distilled-Standard-Modeling-Language/dp/0321193687)
5. 添加Google Test，自动化测试代码。B站上目前还没有中文Google Test 的教程，以后可以考虑做一个教程。

## 贡献
如果你觉得某一个部分的代码可以加以改进，请提出issue，共同来完成一个C++的模板项目。
