#include <iostream>
#include "../Project2/clsMyQueue.h"
#include "MyDate/clsDate.h"

class clsQueueLine
{

private:
    string _Prefix;
    int _AvgWaitTime;
    int _TotalTickets;
    class clsTicket
    {
    private:
        short _TicketNumber = 0;
        string _Prefix;
        string _TicketTime;
        short _WaitingClients = 0;
        short _AvgServeWaitTime;
        short _ExpectedServeTime = 0;

    public:
        clsTicket(string Prefix = "", short TicketNumber = 0, string TicketTime = "", short WaitingClients = 0, short AvgServeWaitTime = 0)
        {
            _TicketNumber = TicketNumber;
            _TicketTime = TicketTime;
            _Prefix = Prefix;
            _WaitingClients = WaitingClients;
            _AvgServeWaitTime = AvgServeWaitTime;
        }

        string GetPrefix()
        {
            return _Prefix;
        }
        string GetTicketNumber()
        {
            return to_string(_TicketNumber);
        }
        string GetFullNumber()
        {
            return _Prefix + to_string(_TicketNumber);
        }
        string GetTicketTime()
        {
            return _TicketTime;
        }
        short GetWaitingClients()
        {
            return _WaitingClients;
        }
        short GetAvgServeWaitTime()
        {
            return _AvgServeWaitTime;
        }
        short GetExpectedServeTime()
        {
            return _AvgServeWaitTime * _WaitingClients;
        }

        void Print()
        {
            cout << "\n\t\t\t  __________________________________\n";
            cout << "\n\t\t\t\t    " << GetFullNumber();
            cout << "\n\n\t\t\t    Date: " << _TicketTime;
            cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
            cout << "\n\t\t\t    Serve Time In";
            cout << "\n\t\t\t       " << GetExpectedServeTime() << " Minutes.";
            cout << "\n\t\t\t  __________________________________\n";
        }
    };

public:
    clsMyQueue<clsTicket> Queue;

    clsQueueLine(string Prefix, int AvgWaitTime)
    {
        _Prefix = Prefix;
        _TotalTickets = 0;
        _AvgWaitTime = AvgWaitTime;
    }
    string GetPrefix() { return _Prefix; }
    int GetAvgWaitTime() { return _AvgWaitTime; }

    void PrintInfo()
    {
        cout << "-----------------------------------------------" << endl;
        cout << "\t\t Queue Info:" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Prefix: " << _Prefix << endl;
        cout << "Total Tickets: " << _TotalTickets << endl;
        cout << "Served Clients: " << ServedClients() << endl;
        cout << "Waiting Clients: " << WaitingClients() << endl;
        cout << "-----------------------------------------------" << endl;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket ticket(_Prefix, _TotalTickets, clsDate::GetSystemDateTimeString(), WaitingClients(), _AvgWaitTime);
        Queue.push(ticket);
    }

    void PrintTicketsLineRTL()
    {
        cout << "\nTicket: ";
        int Size = Queue.Size();
        for (int i = 0; i < Size; i++)
        {
            cout << Queue.GetItem(i)->GetFullNumber();
            if (i < Size - 1)
                cout << " <-- ";
        }
    }

    void PrintTicketsLineLTR()
    {
        cout << "\nTicket: ";
        int Size = Queue.Size();
        for (int i = Size - 1; i >= 0; i--)
        {
            cout << Queue.GetItem(i)->GetFullNumber();
            if (i != 0)
                cout << " --> ";
        }
    }

    void PrintAllTickets()
    {
        cout << "\nAll Tickets Info: " << endl;
        cout << "-----------------------------------------------" << endl;
        int Size = Queue.Size();
        for (int i = 0; i < Size; i++)
        {
            cout << "-----------------------------------------------" << endl;
            Queue.GetItem(i)->Print();
            cout << endl;
            cout << "-----------------------------------------------" << endl;
        }
    }

    bool ServeNextClient()
    {
        if (!Queue.IsEmpty())
        {
            Queue.pop();
            return true;
        }
        return false;
    }

    int WaitingClients()
    {
        return Queue.Size();
    }

    int ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }
};