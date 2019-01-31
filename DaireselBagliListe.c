#include <stdlib.h>
#include <stdio.h>

//Yap�m�z� olu�turuyoruz. Teky�nl� ba�l� listeden farkl� yok. fark kullan�mda ortaya ��k�cak.
struct Node
{
	int data;
	struct Node *next;
};

//Lisemize eleman eklemeye yarayacak methodumuzu yaz�yoruz.
void push(struct Node **head_ref, int data)//ilk eleman eklenirken head de�i�icek bu y�zden "**" ile d���m� al�yoruz.
{
	struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));//yeni olu�turucag�m�z eleman i�in ramden yer al�yoruz.
	struct Node *temp = *head_ref;//head �m�z� tutmak i�in yap�m�zdan kopya olu�turuyoruz.
	ptr1->data = data;//parametre olarak gelen datay� olu�turdugumuz tre1 e at�yoruz.
	ptr1->next = *head_ref;//olu�turdugumuz yap�n�n next(i�aretci)si ne head � at�yoruz.


	if (*head_ref != NULL)//head bo�de�ilse while d�ng�s� ile sonuncu elamana gidip next ine ptr1 i at�yoruz.
	{
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else//e�er head bo� ise ba�ka eleman olmad�g�ndan direk next olarak kendisini g�steriyor.
		ptr1->next = ptr1; 

	*head_ref = ptr1;// son olarak head �m�za olu�turdugumuz eleman� at�yoruz.
}

//D�ng�m�z� yazd�racak fonksiyonumuzu yaz�yoruz.
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do// do while kullanmam�z�n sebebi en son elaman�da yazd�r�cak olmam�z.
		{
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);// d�ng�m�z tekrar head a gelesiye kadar d�n�yor ve elemanlar� yazd�r�yor.
	}
}


int main()
{

	struct Node *head = NULL;//yap�m�z� olu�turuyoruz. direk null at�yoruz. 
	

	//eleman ekliyoruz. 
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);

	printf("Dairesel Ba�l� liste elemanlar� : \n ");//\n alt sat�ra ge�me komutu
	printList(head);//yazd�rmak i�in fonkisyonumuzu �ag�r�yoruz.

	return 0;
}