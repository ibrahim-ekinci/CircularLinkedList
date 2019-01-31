#include <stdlib.h>
#include <stdio.h>

//Yapýmýzý oluþturuyoruz. Tekyönlü baðlý listeden farklý yok. fark kullanýmda ortaya çýkýcak.
struct Node
{
	int data;
	struct Node *next;
};

//Lisemize eleman eklemeye yarayacak methodumuzu yazýyoruz.
void push(struct Node **head_ref, int data)//ilk eleman eklenirken head deðiþicek bu yüzden "**" ile düðümü alýyoruz.
{
	struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));//yeni oluþturucagýmýz eleman için ramden yer alýyoruz.
	struct Node *temp = *head_ref;//head ýmýzý tutmak için yapýmýzdan kopya oluþturuyoruz.
	ptr1->data = data;//parametre olarak gelen datayý oluþturdugumuz tre1 e atýyoruz.
	ptr1->next = *head_ref;//oluþturdugumuz yapýnýn next(iþaretci)si ne head ý atýyoruz.


	if (*head_ref != NULL)//head boþdeðilse while döngüsü ile sonuncu elamana gidip next ine ptr1 i atýyoruz.
	{
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else//eðer head boþ ise baþka eleman olmadýgýndan direk next olarak kendisini gösteriyor.
		ptr1->next = ptr1; 

	*head_ref = ptr1;// son olarak head ýmýza oluþturdugumuz elemaný atýyoruz.
}

//Döngümüzü yazdýracak fonksiyonumuzu yazýyoruz.
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do// do while kullanmamýzýn sebebi en son elamanýda yazdýrýcak olmamýz.
		{
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);// döngümüz tekrar head a gelesiye kadar dönüyor ve elemanlarý yazdýrýyor.
	}
}


int main()
{

	struct Node *head = NULL;//yapýmýzý oluþturuyoruz. direk null atýyoruz. 
	

	//eleman ekliyoruz. 
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);

	printf("Dairesel Baðlý liste elemanlarý : \n ");//\n alt satýra geçme komutu
	printList(head);//yazdýrmak için fonkisyonumuzu çagýrýyoruz.

	return 0;
}