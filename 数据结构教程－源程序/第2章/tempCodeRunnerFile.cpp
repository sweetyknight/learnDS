if (L->next!=L)		//��������Ϊ�ձ�ʱ
	{
		if (i==1)
		{
			e=L->next->data;
			return 1;
		}
		else			//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-1 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)
				return 0;
			else
			{
				e=p->data;
				return 1;
			}
		}
	}
	else				//������Ϊ�ձ�ʱ
		return 0;