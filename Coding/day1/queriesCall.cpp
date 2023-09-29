#include <bits/stdc++.h>
using namespace std;
int countIncorrect = 0;
typedef struct lt
{
    int hour;
    int minute;
    int second;
} HTime;

typedef struct cal
{
    string fPhoneNumber, dPhoneNumber;
    string date;
    HTime startTime, endTime;
} callDetail;
vector<callDetail> listCall;

void saveData()
{
    while (true)
    {
        callDetail newData;
        string call;
        cin >> call;
        if (call == "#")
        {
            break;
        }
        cin >> newData.fPhoneNumber;
        cin >> newData.dPhoneNumber;
        if (!all_of(newData.fPhoneNumber.begin(), newData.fPhoneNumber.end(), ::isdigit))
        {
            countIncorrect++;
        }
        if (!all_of(newData.dPhoneNumber.begin(), newData.dPhoneNumber.end(), ::isdigit))
        {
            countIncorrect++;
        }

        cin >> newData.date;
        string sTime, eTime;
        cin >> sTime >> eTime;

        newData.startTime.hour = stoi(sTime.substr(0, 2));
        newData.startTime.minute = stoi(sTime.substr(3, 2));
        newData.startTime.second = stoi(sTime.substr(6, 2));

        newData.endTime.hour = stoi(eTime.substr(0, 2));
        newData.endTime.minute = stoi(eTime.substr(3, 2));
        newData.endTime.second = stoi(eTime.substr(6, 2));
        listCall.push_back(newData);
    }
}

int countNumberCallFrom(string phoneNumber)
{
    int count = 0;

    for (unsigned int i = 0; i < listCall.size(); i++)
    {
        if (listCall[i].fPhoneNumber == phoneNumber)
        {
            count++;
        }
    }
    return count;
}

int countDistance(HTime start, HTime end)
{
    return -(3600 * (start.hour - end.hour) + 60 * (start.minute - end.minute) + start.second - end.second);
}

int countTimeCallsFrom(string phoneNumber)
{
    int totalTime = 0;
    for (unsigned int i = 0; i < listCall.size(); i++)
    {
        if (phoneNumber == listCall[i].fPhoneNumber)
        {
            totalTime += countDistance(listCall[i].startTime, listCall[i].endTime);
        }
    }
    return totalTime;
}

void queries()
{
    while (true)
    {
        string request;
        cin >> request;
        if (request == "#")
        {
            break;
        }
        if (request == "?check_phone_number")
        {
            if (countIncorrect == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << countIncorrect << endl;
            }
            continue;
        }
        else if (request == "?number_total_calls")
        {
            cout << listCall.size() << endl;
            continue;
        }
        string pNumber;
        cin >> pNumber;
        if (request[1] == 'c')
        {
            cout << countTimeCallsFrom(pNumber) << endl;
        }
        else
        {
            cout << countNumberCallFrom(pNumber) << endl;
        }
    }
}
int main()
{
    saveData();
    queries();
}