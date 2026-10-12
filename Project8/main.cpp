#include <iostream>
#include "clsQueueLine.h"

int main()
{

    clsQueueLine paybillsQueue("A", 10);
    paybillsQueue.PrintInfo();

    paybillsQueue.IssueTicket();
    paybillsQueue.IssueTicket();

    paybillsQueue.IssueTicket();
    paybillsQueue.IssueTicket();

    paybillsQueue.PrintInfo();

    paybillsQueue.PrintTicketsLineRTL();

    paybillsQueue.PrintTicketsLineLTR();
    paybillsQueue.PrintAllTickets();

    paybillsQueue.ServeNextClient();
    paybillsQueue.ServeNextClient();
    paybillsQueue.ServeNextClient();

    paybillsQueue.ServeNextClient();

    paybillsQueue.PrintInfo();
}