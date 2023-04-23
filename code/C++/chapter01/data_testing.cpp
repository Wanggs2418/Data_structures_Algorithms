#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

// O(n)
void dataScaleTest1(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        k++;
    }
}

// O(n^2)
void dataScaleTest2(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            k++;
        }
    }
}
// O(nlogn)
void dataScaleTest3(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 1; j < n; j = j * 2)
        {
            k++;
        }
    }
}

// O(n^3)
void dataScaleTest4(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; i < n; i++)
        {
            for (long long m = 0; m < n; m++)
            {
                k++;
            }
        }
    }
}

int main()
{
    // 确定数据规模
    long long n;
    while (1)
    {
        cout << "输入数据规模n:";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        // O(n) 1s内大约处理 1×10^9 次计算
        dataScaleTest1(n);
        // O(n^2) 1s 内大约处理 5×10^4, O(n) 计算的数开根号
        // dataScaleTest2(n);
        // O(nlogn) 1s 内大约处理 5×10^7 ,比 O(n) 少一个数量级
        // dataScaleTest3(n);
        // 有待考证，O(n^3) 1s 内处理约 10^5
        // dataScaleTest4(n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        cout << "耗时:"  << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }
}