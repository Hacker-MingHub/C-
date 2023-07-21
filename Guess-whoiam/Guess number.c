#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>

void menu() {
  printf("*****************************\n");
  printf("*********** 1.play **********\n");
  printf("*********** 0.exit **********\n");
  printf("*****************************\n");
}

void game() {
  int rand_num = rand() % 100 + 1;
  int input = 0;

  while (true)
  {
    printf("������µ�����>:");
    scanf("%d", &input);
    if (input > rand_num)
    {
      printf("�´���\n");
    }
    else if (input < rand_num)
    {
      printf("��С��\n");
    }
    else
    {
      printf("��ϲ�㣬�¶���\n");
      break;
    }

  }


}

int main(int argc, char const* argv[])
{
  int input = 0;
  srand((unsigned)time(NULL));
  do
  {
    menu();
    printf("��ѡ��>:");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
      game();
      break;
    case 0:
      printf("�˳���Ϸ");
      break;
    default:
      printf("ѡ�����,����������!\n");
      break;
    }
  } while (input);

  return 0;
}
