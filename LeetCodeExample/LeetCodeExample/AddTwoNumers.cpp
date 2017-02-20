#include "AddTwoNumers.h"

ListNode * AddTwoNumbers::addTwoNumbers(ListNode * l1, ListNode * l2)
{
    // Check l1 or l2 is empty 
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    else if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;

    ListNode *first  = l1;
    ListNode *second = l2;

    int sum = 0, num = 0, add = 0;

    ListNode *result = nullptr;
    ListNode *end    = nullptr;

    while (first != nullptr && second != nullptr)
    {
        sum = first->val + second->val + add;

        num = 0;
        add = 0;

        if (sum != 0)
        {
            num = sum % 10;
            add = sum / 10.f;
        }

        if (result == nullptr)
        {
            result = new ListNode(num);
            end = result;
        }
        else
        {
            end->next = new ListNode(num);
            end = end->next;
        }
       
        first = first->next;
        second = second->next;
    }

    // l1 and l2 has same length, no more loop 
    if (first == nullptr && second == nullptr)
    {
        if (add != 0)
            end->next = new ListNode(add);
        return result;
    }
    
    ListNode *rest = nullptr;
    if (first == nullptr)
        rest = second;
    else
        rest = first; 

    // add again, using rest of list
    while (rest != nullptr)
    {
        if (add == 0)
        {
            end->next = rest;
            return result;
        }

        sum = rest->val + add;

        num = 0;
        add = 0;

        if (sum != 0)
        {
            num = sum % 10;
            add = sum / 10.f;
        }

        end->next = new ListNode(num);
        end = end->next;

        rest = rest->next;
    }

    if(add != 0)
        end->next = new ListNode(add);

    return result;
}
