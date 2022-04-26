#include <iostream>
#include <vector>
using namespace std;


//输入一行整数，回车键结束
void test1() {
    vector<int> input;
    int number;
    while (cin >> number)
    {
        input.push_back(number);
        //cout << "空格字符" << cin.get() - ' ' << endl;
	    if (cin.get() == '\n') //按下回车键推出循环
		    break;
        cout << "t" << endl;
    }
    for(auto& it : input)
         cout << it << ' ';
    cout << endl;
}

int main()
{
    test1();
    return 0;   
}