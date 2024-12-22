#include <iostream>
#include <vector>
#include <algorithm>

class BankAlgorithm
{
private:
    std::vector<std::vector<int>> max;             // ����������
    std::vector<std::vector<int>> currentAllocate; // ��ǰ�������Դ����
    std::vector<std::vector<int>> need;            // ��Ȼ��Ҫ����Դ����
    std::vector<int> available;                    // ������Դ����
    std::vector<bool> finish{};                    // ��ǽ����Ƿ����
    int processNum;                                // ������
    int resourceNum;                               // ��Դ������
public:
    BankAlgorithm(int p, int r) : processNum(p), resourceNum(r) // ��ʼ��
    {
        max.resize(p, std::vector<int>(r));
        currentAllocate.resize(p, std::vector<int>(r));
        need.resize(p, std::vector<int>(r));
        available.resize(r);
        finish.resize(p);
        fill(finish.begin(), finish.end(), false); // ��ʼ����ʱ��ȫ����δ���
    }

    void inputData()
    {
        std::cout << "please input max matrix:" << std::endl;
        // ��������������
        for (int i = 0; i < processNum; i++)
        {
            for (int j = 0; j < resourceNum; j++)
            {
                std::cin >> max[i][j];
            }
        }
        std::cout << "please input currentAllocate matrix:" << std::endl;
        // ���뵱ǰ�������
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
        // ���뵱ǰ������Դ
        for (int i = 0; i < resourceNum; i++)
        {
            std::cin >> available[i];
        }
    }

    // �жϰ�ȫ����
    bool isSafe()
    {
        std::vector<int> work = available; //�ڷ�����Դ��ʱ���Ѿ�����
        // fill(finish.begin(), finish.end(), false); // ��ʼʱȫ��û�����
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
            bool found = false; // ��ʼʱû���ҵ���ȫ����
            for (int i = 0; i < processNum; i++)
            {
                // ��ǰ�����process i
                if (!tempFinish[i]) // ����iû�����
                {
                    bool canAllocate = true;
                    // ����Ƿ����㹻����Դ�����process i
                    for (int j = 0; j < resourceNum; j++)
                    {
                        if (need[i][j] > work[j])
                        {
                            canAllocate = false;
                            break;
                        }
                    }

                    if (canAllocate) // ������Է���
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
            if (!found) // ��ǰ���ֲ�����
            {
                std::cout << "currnt system is unsafe." << std::endl;
                return false;
            }
        }
        return true; // ���н������ ϵͳ��ȫ
    }

    bool requestResouce(int processId, const std::vector<int> &request) // ������Դ
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

        // ���Է�����Դ
        // for (int i = 0; i < resourceNum; i++)
        // {
        //     available[i] -= request[i];
        //     currentAllocate[processId][i] += request[i];
        //     need[processId][i] -= request[i];
        //     finish[processId] = true;
        // }
        showData();
        // ����֮���ж��Ƿ�ȫ
        if (isSafe())
        {
            // ����ǰ�ȫ��
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
            // �������ȫ ���лع�
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
    std::cout << "please input the processNum and resourceNum��";
    std::cin >> processNum >> resourceNum;
    BankAlgorithm *bank = new BankAlgorithm(processNum, resourceNum);
    bank->inputData();
    // ϵͳ��ʼ��ȫ�Լ��
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