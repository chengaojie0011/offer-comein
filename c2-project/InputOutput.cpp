////
//// Created by 陈高杰 on 2020/3/28.
////
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//int  main()
//{
//    //cin，输入结束时（enter）输入存储到缓冲区，>>从缓冲区中读取数据,char,int ,string都可以输出，但不能有空格
//    int a, b;
//    char c;
//    cin >> a >> b;
//    cout << "a=" << a << ' ' << "b=" << b << endl;
//    cin >> c;
//    cout << "c=" << c << endl;/
//    string str;
//    cin >> str;
//    cout << "str=" << str << endl;
//
//    //cin.get()，获取缓冲区的一个字符，遇到空格或换行时当前读取结束，但下一次会读取空格或换行
//    char ch1, ch2, ch3;
//    cin.get(ch1);
//    cin.get(ch2);
////    ch2 = cin.get();
//    cin.get(ch3);
//    cout << "1=" << ch1 << endl;
//    cout << "2=" <<ch2 << endl;
//    cout << "3=" << ch3 << endl;
//
//    //cin.get(array,length)，从缓冲区读取字符串。遇到空格不结束，遇到换行结束，但下一次要读取换行符
//    //遇到空格不停止，换行符直接结束
//    char ch[5];
//    char chc[5];
//    cin.get(ch, 5);
//    cin.get(chc, 5);
//    cout << "1="<< ch << endl;
//    cout << "2=" << chc << endl;
//
//    //cin.getline(string str,int length),从缓冲区读取字符串。遇到空格不结束，遇到换行结束，下一次不读取换行符
//    //遇到换行不结束，进入下一条输入流
//    char chh[10];
//    char chh1[10];
//    cin.getline(chh, 10);
//    cin.getline(chh1, 6);
//    cout << chh << endl;
//    cout << chh1 << endl;
//
//    //getline(),读取字符串包含空格，遇到换行结束，不包括换行
//    string s;
//    getline(cin, s);
//    string s1;
//    getline(cin, s1);
//    cout << s << endl;
//    cout << s1 << endl;
//
//    //用','隔开
//    char a1[5][10];
//    int i;// 每次遇到',' 就终止了 ，不保留在缓冲区。
//    for (i = 0; i<4; i++)
//        cin.getline(a1[i], 10, ',');
//    // 最后一个是输入5'/n'没有','不符合上面的式子，需要重新把缓冲区中的读出来
//    cin.getline(a1[i], 10);
//    for (i = 0; i<5; i++)
//        cout << a1[i] << endl;
//
//    //以空格为间隔的数组
//    int n;
//    cin >> n;
//    vector<int> a2(n, 0);
//    int tmp;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a2[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << a2[i];
//    }
//
//    //getline获取一行数据，再用stringstream把数字提出来,空格划开,不能有字母
//    string line;
//    getline(cin, line);
//    istringstream s1(line);
//    int tmp1;
//    vector<int> data;
//    while (s1 >> tmp1)
//        data.push_back(tmp1);
//    for (int i = 0; i < data.size(); i++){
//        cout << data[i]<<endl;
//    }
//
//    //将数字转化成字符串
//    vector<int> num{ 3,32,321 };
//    vector<string> strNum;
//    for (int i = 0; i<num.size(); ++i)
//    {
//        stringstream ss;
//        ss << num[i];
//        cout << "string:" << ss.str() << endl;
//    }
//
//    return 0;
//}