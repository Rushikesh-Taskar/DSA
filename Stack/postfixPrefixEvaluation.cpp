#include <bits/stdc++.h>
using namespace std;
bool isOperand(char c)
{
    return isdigit(c);  
    // isdigit is inbuilt function which check whether char is
    // digit or not if digit then write 1 
}

// for single digit like 9+7,8*7
int postfixevaluation(string post)
{
    stack<double> sp;
    for (int i = 0; i < post.size(); i++)
    {
        if (isOperand(post[i]))
        { // Push operand to Stack
            // To convert char post[i] to digit subtract
            // '0' from post[i].
            sp.push(post[i] - '0');
        }
        else
        {
            double val1 = sp.top();
            sp.pop();
            double val2 = sp.top();
            sp.pop();
            switch (post[i])
            {
            case '+':
            {
                sp.push(val1 + val2);
                break;
            }
            case '-':
            {
                sp.push(val2 - val1);
                break;
            }
            case '*':
            {
                sp.push(val1 * val2);
                break;
            }
            case '/':
            {
                sp.push(val2 / val1);
                break;
            }
            case '^':
            {
                sp.push(pow(val2, val1));
                break;
            }
            }
        }
    }
    cout << "expression value is " << sp.top() << endl;
    return 0;
}

int prefixevaluation(string post)
{
    stack<double> sp;

    reverse(post.begin(), post.end());

    for (int i = 0; i < post.size(); i++)
    {
        if (isOperand(post[i]))
        {
            // Push operand to Stack
            // To convert char post[i] to digit subtract
            // '0' from post[i].
            sp.push(post[i] - '0');
        }
        else
        {
            double val1 = sp.top();
            sp.pop();
            double val2 = sp.top();
            sp.pop();
            switch (post[i])
            {
            case '+':
            {
                sp.push(val1 + val2);
                break;
            }
            case '-':
            {
                sp.push(val1 - val2);
                break;
            }
            case '*':
            {
                sp.push(val1 * val2);
                break;
            }
            case '/':
            {
                sp.push(val1 / val2);
                break;
            }
            case '^':
            {
                sp.push(pow(val1, val2));
                break;
            }
            }
        }
    }
    cout << "expression value is " << sp.top() << endl;
    return 0;
}

// for more than one digit linke 678+87 ,98*7876
int postfixmore(string post)
{
    stack<double> sp;
    for (int i = 0; i < post.size(); i++)
    {
        // expression like "23 34 + / 56"
        if (post[i] == ' ')
        { // space then continue
            continue;
        }
        if (isdigit(post[i]))
        {
            double num = 0, j = i;
            while (i < post.size() && isdigit(post[i]))
            {
                i++;
            }

            i--;

            // from [i, j] exprsn contains a number
            for (int k = j; k <= i; k++)
            {
                // num*10 because we have to convert
                //  digit to no
                //  initially  num=0
                // ex. 12 = 0*10+1=1 , 1*10 +2 =12
                // ex.234 = 2*0 +2 =2 , 2*10 +3 =23 , 23*10 +4 = 234
                
                num = num * 10 + double(post[k] - '0'); // typecast
            }
            sp.push(num);
        }
        else
        {
            double val1 = sp.top();
            sp.pop();
            double val2 = sp.top();
            sp.pop();
            switch (post[i])
            {
            case '+':
            {
                sp.push(val1 + val2);
                break;
            }
            case '-':
            {
                sp.push(val2 - val1);
                break;
            }
            case '*':
            {
                sp.push(val1 * val2);
                break;
            }
            case '/':
            {
                sp.push(val2 / val1);
                break;
            }
            case '^':
            {
                sp.push(pow(val2, val1));
                break;
            }
            }
        }
    }
    cout << "expression value is " << sp.top() << endl;
    return 0;
}

int prefixmore(string post)
{
    stack<double> sp;

    for (int i = post.size() - 1; i >= 0; i--)
    {

        if (post[i] == ' ')
        {
            continue;
        }
        if (isdigit(post[i]))
        {
            double num = 0, j = i;
            while (i < post.size() && isdigit(post[i]))
            {
                i--;
            }

            i++;

            // from [i, j] exprsn contains a number
            for (int k = i; k <= j; k++)
            {
                num = num * 10 + double(post[k] - '0');
            }
            sp.push(num);
        }
        else
        {
            double val1 = sp.top();
            sp.pop();
            double val2 = sp.top();
            sp.pop();
            switch (post[i])
            {
            case '+':
            {
                sp.push(val1 + val2);
                break;
            }
            case '-':
            {
                sp.push(val1 - val2);
                break;
            }
            case '*':
            {
                sp.push(val1 * val2);
                break;
            }
            case '/':
            {
                sp.push(val1 / val2);
                break;
            }
            case '^':
            {
                sp.push(pow(val1, val2));
                break;
            }
            }
        }
    }
    cout << "expression value is " << sp.top() << endl;
    return 0;
}
int main()
{

    int p = 0;
    do
    {  
        cout << "enter 1 for single digit postfix" << endl;
        cout << "enter 2 for single digit prefix" << endl;
        cout << "enter 3 for multiple digit postfix " << endl;
        cout << "enter 4 for multiple digit prefix" << endl;
        cout << "enter 5 for exit " << endl;
        int g;
        cin >> g;
        switch (g)
        {
        case 1:
        {
            cout << "enter postfix expression" << endl;
            string post;
            cin >> post;
            postfixevaluation(post);
            break;
        }
        case 2:
        {
            cout << "enter prefix expression" << endl;
            string pre;
            cin >> pre;
            prefixevaluation(pre);
            break;
        }
        case 3:
        {
            cout << "enter postfix expression" << endl;
            string post;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,post);

            postfixmore(post);
            break;
        }
        case 4:
        {  
            cout << "enter prefix expression" << endl;
            string pre;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin, pre);

            prefixmore(pre);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        }
    } while (p != 1);

    // cin>>post;
    // getline(cin ,post);  // for space
    // postfixevaluation(post);
    // prefixevaluation(post);
    // postfixmore(post);
    // prefixmore(post);
}