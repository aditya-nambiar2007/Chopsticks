#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>

void stop()
{
  while (true)
  {
  }
}

class output
{
public:
  int from, to, exists;
  char s;

  output(char x[])
  {
    FILE *abc;
    char ret[4];
    abc = _popen(x, "r");
    if (abc != NULL)
    {
      fgets(ret, sizeof(ret), abc);
      _pclose(abc);
      from = ret[0] - '0';
      to = ret[1] - '0';
      s = ret[2];
      exists = 1;
    }
    else
    {
      exists = 0;
    }
  }
};
char c(int i)
{
  switch (i)
  {
  case 1:
    return '1';
    break;
  case 2:
    return '2';
    break;
  case 3:
    return '3';
    break;
  case 4:
    return '4';
    break;
  case 5:
    return '5';
    break;
  case 0:
    return '0';
    break;
  }
}

int p1[2] = {1, 1};
int comp[2] = {1, 1};
char alg_code[10];
int main()
{
  while (true)
  {
    std::cout << " ____________________________________________________" << '\n';
    std::cout << "|                   CHOPSTICKS                       |" << '\n';
    std::cout << "|RULES                                               |" << '\n';
    std::cout << "|1.You can add your count to opponent's hand         |" << '\n';
    std::cout << "|2.You can transfer the count between your hands     |" << '\n';
    std::cout << "|3.Once a count of 5 is reached,The hand is disabled |" << '\n';
    std::cout << "|4.The last person standing with a hand less than 5  |" << '\n';
    std::cout << "|  will be declared the winner.                      |" << '\n';
    std::cout << "|5.Each person has 2 hands :                         |" << '\n';
    std::cout << "|  i) The hand on the left is coded 1.               |" << '\n';
    std::cout << "|  ii)The hand on the right is coded 2.              |" << '\n';
    std::cout << "|____________________________________________________|" << "\n\n";
    std::cout << "Enter Algorithm Code : ";
    std::cin >> alg_code;
    char f[] = {'C', ':', '/', 'c', 'o', 'd', 'e', 's', '/', alg_code[0], alg_code[1], alg_code[2], alg_code[3], alg_code[4], alg_code[5], alg_code[6], alg_code[7], alg_code[8], alg_code[9], '.', 'e', 'x', 'e', ' ', '1', '2', '1', '2'};
    output exe(f);
    if (exe.exists==0)
    {
      system("cls");
      std::cout << "***Algorithm Code Was Not Found\n";
      continue;
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    int pos[2];
    char self, code[4],conf;
    system("cls");
    std::cout << "Algorithm Code : " << alg_code << std::endl;
    int arr[4] = {p1[0], p1[1], comp[0], comp[1]};
    if ((arr[0] != 5 || arr[1] != 5) && (arr[2] == 5 && arr[3] == 5))
    {
      std::cout << " ____________________________________________________" << '\n';
      std::cout << "|                                                    |" << '\n';
      std::cout << "|                    YOU WON!!!!                     |" << '\n';
      std::cout << "|____________________________________________________|" << '\n';
      stop();
    }
    else if ((arr[0] == 5 && arr[1] == 5) && (arr[2] != 5 || arr[3] != 5))
    {
      std::cout << " ____________________________________________________" << '\n';
      std::cout << "|                                                    |" << '\n';
      std::cout << "|                   YOU LOST!!!!                     |" << '\n';
      std::cout << "|____________________________________________________|" << '\n';
      stop();
    }

    std::cout << std::string(p1[0], '|') << std::string(10 - p1[0], ' ') << std::string(p1[1], '|') << "\n\n\n\n";
    std::cout << std::string(comp[0], '|') << std::string(10 - comp[0], ' ') << std::string(comp[1], '|') << std::endl;
    std::cout << "\n Self Transfer (Y/N) : ";
    std::cin >> self;
    std::cout << "\n From : ";
    std::cin >> pos[0];
    std::cout << "\n To   : ";
    std::cin >> pos[1];
    std::cout << "\n Confirm   :";
    std::cin >> conf;
    if(conf=='n'||conf=='N'){continue;}
    if (p1[pos[0] - 1] > 4 || p1[pos[0] - 1] < 0 || comp[pos[1] - 1] > 4 || comp[pos[1] - 1] < 0 || pos[0] == 0)
    {
    }
    else if (self == 'y' || self == 'Y')
    {
      p1[pos[0] - 1]--;
      p1[pos[1] - 1]++;
    }
    else
    {
      p1[pos[0] - 1];
      comp[pos[1] - 1] += p1[pos[0] - 1];
    }
    system("cls");
    std::cout << "Algorithm Code : " << alg_code << std::endl;
    if ((arr[0] != 5 || arr[1] != 5) && (arr[2] == 5 && arr[3] == 5))
    {
      std::cout << " ____________________________________________________" << '\n';
      std::cout << "|                                                    |" << '\n';
      std::cout << "|                    YOU WON!!!!                     |" << '\n';
      std::cout << "|____________________________________________________|" << '\n';
      stop();
    }
    else if ((arr[0] == 5 && arr[1] == 5) && (arr[2] != 5 || arr[3] != 5))
    {
      std::cout << " ____________________________________________________" << '\n';
      std::cout << "|                                                    |" << '\n';
      std::cout << "|                   YOU LOST!!!!                     |" << '\n';
      std::cout << "|____________________________________________________|" << '\n';
      stop();
    }

    std::cout << std::string(p1[0], '|') << std::string(10 - p1[0], ' ') << std::string(p1[1], '|') << "\n\n\n\n";
    std::cout << std::string(comp[0], '|') << std::string(10 - comp[0], ' ') << std::string(comp[1], '|') << std::endl;
    std::cout << "\nWaiting For Opponent....";
    char x[31] = {'C', ':', '/', 'c', 'o', 'd', 'e', 's', '/', alg_code[0], alg_code[1], alg_code[2], alg_code[3], alg_code[4], alg_code[5], alg_code[6], alg_code[7], alg_code[8], alg_code[9], '.', 'e', 'x', 'e', ' ', c(p1[0]), c(p1[1]), c(comp[0]), c(comp[1])};
    output val(x);
    Sleep(1000);
    if (p1[val.from - 1] > 4 || p1[val.from - 1] < 0 || comp[val.to - 1] > 4 || comp[val.to - 1] < 0)
    {
    }
    else
    {
      if (val.s == 's' || val.s == 'S')
      {
        if (comp[val.from] != 0)
        {

          comp[val.from - 1]--;
          comp[val.to - 1]++;
        }
      }
      else
      {
        comp[val.from - 1];
        p1[val.to - 1] += comp[val.from - 1];
      }
    }
    if (p1[0] > 5)
    {
      p1[0] = 5;
    }
    if (p1[1] > 5)
    {
      p1[1] = 5;
    }
    if (comp[0] > 5)
    {
      comp[0] = 5;
    }
    if (comp[1] > 5)
    {
      comp[1] = 5;
    }
  }
}