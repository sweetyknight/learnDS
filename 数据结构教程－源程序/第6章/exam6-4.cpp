int f(BTNode *b)
{
	if (b==NULL) 
		return(0);	//�ն������Ľ�����Ϊ0
	else
		return(f(b->lchild)+f(b->rchild)+1);
}
