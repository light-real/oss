#include <iostream>
#include <vector>
#include <algorithm>

class BankAlgorithm
{
private:
    std::vector<std::vector<int>> max;             // 最大需求矩阵
    std::vector<std::vector<int>> currentAllocate; // 当前分配的资源矩阵
    std::vector<std::vector<int>> need;            // 仍然需要的资源矩阵
    std::vector<int> available;                    // 可用资源向量
    std::vector<bool> finish{};                    // 标记进程是否完成
    int processNum;                                // 进程数
    int resourceNum;                               // 资源种类数
public:
    BankAlgorithm(int p, int r) : processNum(p), resourceNum(r) // 初始化
    {
        max.resize(p, std::vector<int>(r));
        currentAllocate.resize(p, std::vector<int>(r));
        need.resize(p, std::vector<int>(r));
        available.resize(r);
        finish.resize(p);
        fill(finish.begin(), finish.end(), false); // 初始化的时候全部是未完成
    }

    void inputData()
    {
        std::cout << "please input max matrix:" << std::endl;
        // 输入最大需求矩阵
        for (int i = 0; i < processNum; i++)
        {
            for (int j = 0; j < resourceNum; j++)
            {
                std::cin >> max[i][j];
            }
        }
        std::cout << "please input currentAllocate matrix:" << std::endl;
        // 输入当前分配矩阵
        for (int i = 0; i < processNum; i++)
        {
            for (int j = 0; j < resourceNum; j++)
            {
                std::cin >> currentAllocate[i][j];
            }
        }

        for (int i = 0; i < processNum; i++)
        {
            for (int j = 0; j < resourceNum; j++)
            {
                need[i][j] = max[i][j] - currentAllocate[i][j];
            }
        }
        std::cout << "please input available vector:" << std::endl;
        // 输入当前可用资源
        for (int i = 0; i < resourceNum; i++)
        {
            std::cin >> available[i];
        }
    }

    // 判断安全序列
    bool isSafe()
    {
        std::vector<int> work = available; //在分配资源的时候已经减了
        // fill(finish.begin(), finish.end(), false); // 初始时全部没有完成
        std::vector<bool> tempFinish = finish;
        int num = 0;
        for (int i = 0; i < finish.size(); i++)
        {
            if (finish[i] == false)
            {
                num++;
            }
        }
        int count = 0;
        while (count < num)
        {
            bool found = false; // 开始时没有找到安全序列
            for (int i = 0; i < processNum; i++)
            {
                // 当前分配给process i
                if (!tempFinish[i]) // 进程i没有完成
                {
                    bool canAllocate = true;
                    // 检查是否有足够的资源分配给process i
                    for (int j = 0; j < resourceNum; j++)
                    {
                        if (need[i][j] > work[j])
                        {
                            canAllocate = false;
                            break;
                        }
                    }

                    if (canAllocate) // 如果可以分配
                    {
                        for (int j = 0; j < resourceNum; j++)
                        {
                            work[j] += currentAllocate[i][j];
                        }
                        count++;
                        tempFinish[i] = true;
                        found = true;
                        // available = work;
                        std::cout << "process " << i << " finish." << std::endl;
                    }
                }
            }
            if (!found) // 当前都分不了了
            {
                std::cout << "currnt system is unsafe." << std::endl;
                return false;
            }
        }
        return true; // 所有进程完成 系统安全
    }

    bool requestResouce(int processId, const std::vector<int> &request) // 请求资源
    {
        for (int i = 0; i < resourceNum; i++)
        {
            if (request[i] > available[i])
            {
                std::cout << "Error:more than available." << std::endl;
                return false;
            }
        }

        for (int i = 0; i < resourceNum; i++)
        {
            if (request[i] > need[processId][i])
            {
                std::cout << "Error:more than the need matrix." << std::endl;
                return false;
            }
        }

        // 尝试分配资源
        // for (int i = 0; i < resourceNum; i++)
        // {
        //     available[i] -= request[i];
        //     currentAllocate[processId][i] += request[i];
        //     need[processId][i] -= request[i];
        //     finish[processId] = true;
        // }
        showData();
        // 分配之后判断是否安全
        if (isSafe())
        {
            // 如果是安全的
            std::cout << "allocate success." << std::endl;

            for (int i = 0; i < resourceNum; i++)
            {
                available[i] += currentAllocate[processId][i];
                // available[i] -= request[i];
                currentAllocate[processId][i] = 0;
                need[processId][i] = 0;
            }
            return true;
        }
        else
        {
            // 如果不安全 进行回滚
            for (int i = 0; i < resourceNum; i++)
            {
                available[i] += request[i];
                currentAllocate[processId][i] -= request[i];
                need[processId][i] += request[i];
                finish[processId] = false;
            }
            std::cout << "rollback success." << std::endl;
            return false;
        }
    }
    void showData()
    {
        // show available vector
        std::cout << "available:";
        for (int i = 0; i < resourceNum; i++)
        {
            std::cout << available[i] << " ";
        }
        std::cout << std::endl;

        // show need matrix
        std::cout << "need Matrix:" << std::endl;
        for (int i = 0; i < processNum; i++)
        {
            for (int j = 0; j < resourceNum; j++)
            {
                std::cout << need[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    int processNum, resourceNum;
    std::cout << "please input the processNum and resourceNum：";
    std::cin >> processNum >> resourceNum;
    BankAlgorithm *bank = new BankAlgorithm(processNum, resourceNum);
    bank->inputData();
    // 系统初始安全性检查
    if (bank->isSafe())
    {
        std::cout << "System is safe." << std::endl;

        std::cout << "would you test the source request?(1:yes 0:no)." << std::endl;
        int choice;
        std::cin >> choice;
        while (choice)
        {
            std::cout << "------------------" << std::endl;
            bank->showData();
            std::cout << "------------------" << std::endl;
            int pid;
            std::vector<int> request(resourceNum);
            std::cout << "please input which process you will use." << std::endl;
            std::cin >> pid;
            std::cout << "please input the number of resource." << std::endl;
            for (int i = 0; i < resourceNum; i++)
            {
                std::cin >> request[i];
            }
            bank->requestResouce(pid, request);
            // if (!bank->requestResouce(pid, request))
            // {
            //     std::cout << "bank->requestResouce() fail." << std::endl;
            //     break;
            // }

            std::cout << "keep request?(1:yes 0:no)." << std::endl;
            std::cin >> choice;
        }
    }
    else
    {
        std::cout << "System is not safe." << std::endl;
    }
    return 0;
}