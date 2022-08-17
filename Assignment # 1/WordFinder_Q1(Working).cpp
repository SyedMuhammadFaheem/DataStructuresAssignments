#include<bits/stdc++.h>
using namespace std;

bool traverseRight(int m, int j, int rows, int cols, char **array, vector<string> character, int find)
{
   
    int length = character[find].length();
  
    if (cols - j < length)
    {
        return false;
    }
  
    int times;
    int remaining = cols - j;
    if (remaining > length)
    {
        times = length;
    }
    else
    {
        times = cols;
    }
    
    int index = 0;
    int wildcard = 0;
    for (int k = j; k < times; k++)
    {
        if (array[m][k] == '+')
        {
            index++;
            continue;
        }
        
        if (array[m][k] == '*')
        {
            
            if (array[m][times - 1] == character[find][length - 1])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if (array[m][k] != character[find][index])
        {
            return false;
        }
        index++;
    }
    return true;
}

bool traverseDown(int i, int j, int rows, int cols, char **array, vector<string> character, int find)
{

    int length = character[find].length();

    if (rows - i < length)
    {
        return false;
    }
    int times;
    int remaining = rows - i;
    if (remaining > length)
    {
        times = length;
    }
    else
    {
        times = cols;
    }
    int index = 0;
    int wildcard = 0;
    for (int k = i; k < times; k++)
    {

        if (array[k][j] == '+')
        {
            index++;
            continue;
        }

        if (array[k][j] == '*')
        {
            if (array[times - 1][j] == character[find][length - 1])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (array[k][j] != character[find][index])
        {
            return false;
        }
        index++;
    }
    return true;
}
int main()
{
    
    int n, m;
    cin >> n;
    cin >> m;
    if (n < 1 || m < 1)
    {
        return 0;
    }
    char **array = new char *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }

  
    int p;
    cin >> p;
    if (p < 1)
    {
        return 0;
    }

    vector<string> character;
    string a;

    for (int i = 0; i < p + 1; i++)
    {
        getline(cin, a);
        character.push_back(a);
    }
    character.erase(character.begin());
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < character[i].size(); j++)
        {
            if (character[i][j] == ' ' || character[i][j] == '\n')
            {
                character[i].erase(character[i].begin() + j);
                j--;
            }
        }
    }
    char check;
    for (int k = 0; k < p; k++)
    {
    
        check = character[k][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (array[i][j] == check || array[i][j] == '+')
                {
                    if (traverseRight(i, j, m, n, array, character, k))
                    {
                        cout << i << " " << j << " R" << endl;
                    }
                    if (traverseDown(i, j, m, n, array, character, k))
                    {
                        cout << i << " " << j << " D" << endl;
                    }
                }
            }
        }
    }
    return 0;
}