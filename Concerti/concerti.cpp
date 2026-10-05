#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct dataa
{
 int g;
 int m;
 int anno;
};
void input(dataa d[],string cant[],string citta[],float bigl[],int cap[],int &lav);
void tabella(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav);
void funzcitta(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav);
void scambiostring(string &x,string &y);
void scambioint(int &x,int &y);
void scambiofloat(float &x,float &y);
void alfabeticocant(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav);
void prezzo(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav);
void dicotomica(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav);
void capienza(string citta[],int cap[],int lav);
int main()
{
	dataa d[500];
	string cant[500],citta[500];
	float bigl[500];
	int cap[500],lav;
	input(d,cant,citta,bigl,cap,lav);
	cout<<"MENU"<<endl;
	int scelta;
	do
	{
		cout<<"1.Visualizza i dati in forma tabellare"<<endl;
		cout<<"2.Visualizza dati dei concerti in una citta"<<endl;
		cout<<"3.Ordine alfabetico per cantante"<<endl;
		cout<<"4.Ordine crescente di prezzo"<<endl;
		cout<<"5.Ricerca dicotomica"<<endl;
		cout<<"6.Citta con capienza maggiore"<<endl;
		cin>>scelta;
	}while (scelta<1||scelta>6);
	switch (scelta)
	{
		case 1:
		tabella(d,cant,citta,bigl,cap,lav);
		break;
		case 2:
		funzcitta(d,cant,citta,bigl,cap,lav);
		break;
		case 3:
		alfabeticocant(d,cant,citta,bigl,cap,lav);
		break;
		case 4:
		prezzo(d,cant,citta,bigl,cap,lav);
		break;
		case 5:
		dicotomica(d,cant,citta,bigl,cap,lav);
		break;
		case 6:
		capienza(citta,cap,lav);
		break;
	}
}
void input(dataa d[],string cant[],string citta[],float bigl[],int cap[],int &lav)
{
	do
	{
		cout<<"Quanti concerti vuoi inserire?(max 500)"<<endl;
		cin>>lav;
	}while (lav<1||lav>500);
	for(int i=0;i<lav;i++)
	{
		cout<<1+i<<" CONCERTO"<<endl;
		cout<<"Inserisci la data (gg/mm/aaaa)"<<endl;
		cin>>d[i].g>>d[i].m>>d[i].anno;
		cout<<"Inserisci il nome del cantante"<<endl;
		cin>>cant[i];
		cout<<"Inserisci la citta"<<endl;
		cin>>citta[i];
		cout<<"Inserisci costo del biglietto"<<endl;
		cin>>bigl[i];
		cout<<"Inserisci capienza massima"<<endl;
		cin>>cap[i];
	}
}
void tabella(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav)
{
	cout<<"Formato tabellare"<<endl;
	cout<<setw(15)<<"Data"<<setw(15)<<"Cantante"<<setw(15)<<"Citta"<<setw(15)<<"Prezzo Biglietto"<<setw(15)<<"Capienza"<<endl;
	for(int i=0;i<lav;i++)
	{
	    cout<<setw(4)<<d[i].g<<"/"
        <<setw(2)<<d[i].m <<"/"
        <<setw(6)<<d[i].anno
        <<setw(15)<<cant[i]
        <<setw(15)<<citta[i]
        <<setw(15)<<bigl[i]
        <<setw(15)<<cap[i]<<endl;
        cout<<"-----------------"<endl;
	}
}
void funzcitta(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav)
{
	string cerca;
	cout<<"Inserire la citta da cercare"<<endl;
	cin>>cerca;
	for(int i=0;i<lav;i++)
	{
		if(cerca==citta[i])
		{
			cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
			cout<<"CANTANTE:"<<cant[i]<<endl;
			cout<<"COSTO BIGLIETTO:"<<bigl[i]<<endl;
			cout<<"CAPIENZA:"<<cap[i]<<endl;
		}
	}
}
void alfabeticocant(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav)
{
	for(int i=0;i<lav-1;i++)
	{
		for(int j=i+1;j<lav;j++)
		{
			if(cant[j]<cant[i])
			{
				scambiostring(cant[i],cant[j]);
				scambiostring(citta[i],citta[j]);
				scambioint(cap[i],cap[j]);
				scambiofloat(bigl[i],bigl[j]);
				dataa temp;
				//giorni
				temp.g=d[i].g;
				d[i].g=d[j].g;
				d[j].g=temp.g;
				//mese
				temp.m=d[i].m;
				d[i].m=d[j].m;
				d[j].m=temp.m;
				//anno
				temp.anno=d[i].anno;
				d[i].anno=d[j].anno;
				d[j].anno=temp.anno;
			}
		}
	}
	for(int i=0;i<lav;i++)
	{
	    cout<<"CANTANTE:"<<cant[i]<<endl;
		cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
		cout<<"COSTO BIGLIETTO:"<<bigl[i]<<endl;
		cout<<"CITTA:"<<citta[i]<<endl;
	}
}
void scambiostring(string &x,string &y)
{
	string temp;
	temp=x;
	x=y;
	y=temp;
}
void scambioint(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void scambiofloat(float &x,float &y)
{
	float temp=x;
	x=y;
	y=temp;
}
void prezzo(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav)
{
	for(int i=0;i<lav-1;i++)
	{
		for(int j=i+1;j<lav;j++)
		{
			if(bigl[j]<bigl[i])
			{
				scambiostring(cant[i],cant[j]);
				scambiostring(citta[i],citta[j]);
				scambioint(cap[i],cap[j]);
				scambiofloat(bigl[i],bigl[j]);
				dataa temp;
				//giorni
				temp.g=d[i].g;
				d[i].g=d[j].g;
				d[j].g=temp.g;
				//mese
				temp.m=d[i].m;
				d[i].m=d[j].m;
				d[j].m=temp.m;
				//anno
				temp.anno=d[i].anno;
				d[i].anno=d[j].anno;
				d[j].anno=temp.anno;
			}
		}
	}
	for(int i=0;i<lav;i++)
	{
		cout<<"COSTO BIGLIETTO:"<<bigl[i]<<endl;
		cout<<"CANTANTE:"<<cant[i]<<endl;
		cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
		cout<<"CITTA:"<<citta[i]<<endl;	
	}
}
void dicotomica(dataa d[],string cant[],string citta[],float bigl[],int cap[],int lav)
{
	string cerca;
	bool trova=false;
	int sx,dx,md,pos;
	alfabeticocant(d,cant,citta,bigl,cap,lav);
	cout<<"Inserisci il nome del cantante da cercare"<<endl;
	cin>>cerca;
	sx=0;
	dx=lav-1;
	do
	{
		md=(sx+dx)/2;
		if(cant[md]==cerca||cant[sx]==cerca||cant[dx]==cerca)
		{
			trova=true;
		}
		else
		{
			if(cant[md]<cerca) sx=md+1;
			else dx=md-1;
		}
	}while(trova==false && sx<=dx);
	if(cant[md]==cerca) pos=md;
	if(cant[sx]==cerca) pos=sx;
	if(cant[dx]==cerca) pos=dx;
	if(trova==true)
	{
		cout<<"Cantante trovato"<<endl;
		cout<<"Citta:"<<citta[pos]<<endl;
	}
	else cout<<"Cantante non trovato"<<endl;
}
void capienza(string citta[],int cap[],int lav)
{
	int max=cap[0],pos=0;
	for(int i=1;i<lav;i++)
	{
		if(cap[i]>max)
		{
			max=cap[i];
			pos=i;
		}
	}
	cout<<"Citta' con capienza maggiore:"<<citta[pos]<<endl;
	cout<<"Capienza:"<<max<<endl;
}
