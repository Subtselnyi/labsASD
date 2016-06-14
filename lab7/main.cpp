#include"stdlib.h"
#include"stdio.h"
#include"string.h"
//if c<>0 then b:=(2*a+c)*2*a;
int k;
struct Tree
{
		int type; //1-операнд, 2-операція,3-sin()
		char mark[10];
		Tree *left;
		Tree *right;
};
struct Tree PP[]= {
	{ 1, "+",  &PP[1], &PP[2] },//0
	{ 2, "9", NULL, NULL },
	{ 1, "*", &PP[3], &PP[4] },
	{ 2, "8", NULL, NULL }, //3
	{ 3, "()", NULL, &PP[5] },
	{ 1, "+", &PP[6], &PP[7] },
	{ 2, "7", NULL, NULL }, //6
	{ 3, "()", NULL, &PP[8] },
	{ 1, "+", &PP[9], &PP[10] }, //8
	{ 1, "*", &PP[11], &PP[12] },
	{ 2, "1", NULL, NULL },//10
	{ 2, "6", NULL, NULL },
	{ 3, "()", NULL, &PP[13] },//12
	{ 1, "-", &PP[14], &PP[15] },
	{ 3, "()", NULL, &PP[16] },//14
	{ 3, "()", NULL, &PP[17] },
	{ 1, "+", &PP[18], &PP[19] },//16
	{ 1, "-", &PP[20], &PP[21] },
	{ 2, "5", NULL, NULL },//18
	{ 2, "4", NULL, NULL },
	{ 2, "3", NULL, NULL },
	{ 2, "2", NULL, NULL }
};
void print_Tree(Tree *p)
{
if (p) {
		switch (p->type)
		{
		case 2:
			{
			printf("%s",p->mark);
			print_Tree(p->left);
			print_Tree(p->right);
			}
			break;
		case 1:
			if(p->left->type==2 &&p->right->type==2)
				printf("%s%s%s",p->left->mark,p->mark,p->right->mark);
			else
			{
                if(p->left->type==2 &&p->right->type!=2)
					{
					 printf("%s%s",p->left->mark,p->mark);
					 print_Tree(p->right);

				}
                if(p->left->type!=2 &&p->right->type==2)
				    {
					 print_Tree(p->left);
					 printf("%s%s",p->mark,p->right->mark);

				}

			}
			break;
		case 3:
			     printf("(");
            if(p->right!=NULL) print_Tree(p->right);
				  printf(")");


				  break;
		}
	}
else return;
}

int main()
{
	 print_Tree(&PP[0]);

return 0;
}
