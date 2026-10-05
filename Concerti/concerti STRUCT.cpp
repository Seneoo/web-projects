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
struct concerto
{
	string cant;
	string citta;
	string luogo;
	float bigl;
	int cap;
	int prenotati;
};
void input(dataa d[],int &lav,concerto c[]);
void tabella(dataa d[],int lav,concerto c[]);
void funzcitta(dataa d[],int lav,concerto c[]);
void scambiostring(string &x,string &y);
void scambioint(int &x,int &y);
void scambiofloat(float &x,float &y);
void alfabeticocant(dataa d[],int lav,concerto c[]);
void prezzo(dataa d[],int lav,concerto c[]);
void dicotomica(dataa d[],int lav,concerto c[]);
void posti(dataa d[],int lav,concerto c[]);
void soldout(dataa d[],int lav,concerto c[]);
void aggiornati(dataa d[],int lav,concerto c[]);
int main()
{
	dataa d[500];
	concerto c[500];
	int lav;
	input(d,lav,c);
	cout<<"MENU"<<endl;
	int scelta;
	do	{
		cout<<"1.Visualizza i dati in forma tabellare"<<endl;
		cout<<"2.Visualizza dati dei concerti in una citta"<<endl;
		cout<<"3.Visualizza concerti con posti disponibili"<<endl;
		cout<<"4.Visualizza concerti Sold out"<<endl;
		cout<<"5.Ordine alfabetico per cantante"<<endl;
		cout<<"6.Ordine crescente di prezzo"<<endl;
		cout<<"7.Aggiorna dati di un concerto"<<endl;
		cout<<"8.Ricerca dicotomica per cantante"<<endl;
		cin>>scelta;
	}while(scelta<1||scelta>8);
	switch(scelta)
	{
		case 1:
		tabella(d,lav,c);
		break;
		case 2:
		funzcitta(d,lav,c);
		break;
		case 3:
		posti(d,lav,c);
		break;
		case 4:
		soldout(d,lav,c);
		break;
		case 5:
		alfabeticocant(d,lav,c);
		break;
		case 6:
		prezzo(d,lav,c);
		break;
		case 7:
		aggiornati(d,lav,c);
		break;
		case 8:
		dicotomica(d,lav,c);
		break;
	}
}
void input(dataa d[],int &lav,concerto c[])
{
	do
	{
		cout<<"Quanti concerti vuoi inserire?(max 500)"<<endl;
		cin>>lav;
	}while(lav<1||lav>500);
	for(int i=0;i<lav;i++)
	{
		cout<<1+i<<" CONCERTO"<<endl;
		cout<<"Inserisci la data (gg mm aaaa)"<<endl;
		cout<<"Giorno"<<endl;
		cin>>d[i].g;
		cout<<"Mese"<<endl;
		cin>>d[i].m;
		cout<<"Anno"<<endl;
		cin>>d[i].anno;
		cin>>d[i].g>>d[i].m>>d[i].anno;
		cout<<"Inserisci il nome del cantante"<<endl;
		cin>>c[i].cant;
		cout<<"Inserisci la citta"<<endl;
		cin>>c[i].citta;
		cout<<"Inserisci il luogo del concerto"<<endl;
		cin>>c[i].luogo;
		cout<<"Inserisci costo del biglietto"<<endl;
		cin>>c[i].bigl;
		cout<<"Inserisci capienza massima"<<endl;
		cin>>c[i].cap;
		cout<<"Inserisci posti prenotati"<<endl;
		cin>>c[i].prenotati;
	}
}
void tabella(dataa d[],int lav,concerto c[])
{
	cout<<"Formato tabellare"<<endl;
	cout<<setw(10)<<"Data"<<setw(15)<<"Cantante"<<setw(15)<<"Citta"<<setw(15)<<"Luogo"<<setw(15)<<"Prezzo"<<setw(10)<<"Cap"<<setw(10)<<"Prenotati"<<setw(10)<<"Disponibili"<<endl;
	for(int i=0;i<lav;i++)
	{
		cout<<setw(2)<<d[i].g<<"/"<<setw(2)<<d[i].m<<"/"<<setw(4)<<d[i].anno
		<<setw(15)<<c[i].cant
		<<setw(15)<<c[i].citta
		<<setw(15)<<c[i].luogo
		<<setw(15)<<c[i].bigl
		<<setw(10)<<c[i].cap
		<<setw(10)<<c[i].prenotati
		<<setw(10)<<c[i].cap-c[i].prenotati<<endl;
		cout<<"-------------------------------"<<endl;
	}
}
void funzcitta(dataa d[],int lav,concerto c[])
{
	string cerca;
	cout<<"Inserire la citta da cercare"<<endl;
	cin>>cerca;
	for(int i=0;i<lav;i++)
	{
		if(c[i].citta==cerca)
		{
			cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
			cout<<"CANTANTE:"<<c[i].cant<<endl;
			cout<<"LUOGO:"<<c[i].luogo<<endl;
			cout<<"PREZZO:"<<c[i].bigl<<endl;
			cout<<"CAPIENZA:"<<c[i].cap<<endl;
			cout<<"PRENOTATI:"<<c[i].prenotati<<endl;
			cout<<"DISPONIBILI:"<<c[i].cap-c[i].prenotati<<endl;
			cout<<"-------------------------------"<<endl;
		}
	}
}
void posti(dataa d[],int lav,concerto c[])
{
	cout<<"Concerti con posti disponibili:"<<endl;
	for(int i=0;i<lav;i++)
	{
		if(c[i].cap-c[i].prenotati>0)
		{
			cout<<"CANTANTE:"<<c[i].cant<<endl;
			cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
			cout<<"CITTA:"<<c[i].citta<<endl;
			cout<<"LUOGO:"<<c[i].luogo<<endl;
			cout<<"PREZZO:"<<c[i].bigl<<endl;
			cout<<"PRENOTATI:"<<c[i].prenotati<<endl;
			cout<<"DISPONIBILI:"<<c[i].cap-c[i].prenotati<<endl;
			cout<<"-------------------------------"<<endl;
		}
	}
}
void soldout(dataa d[],int lav,concerto c[])
{
	cout<<"Tuti i concerti:"<<endl;
	tabella(d,lav,c);
	cout<<"Concerti Sold out:"<<endl;
	cout<<setw(10)<<"Data"<<setw(15)<<"Cantante"<<setw(15)<<"Citta"<<setw(15)<<"Luogo"<<setw(15)<<"Prezzo"<<setw(10)<<"Cap"<<setw(10)<<"Prenotati"<<setw(10)<<"Disponibili"<<endl;
	for(int i=0;i<lav;i++)
	{
		if(c[i].cap-c[i].prenotati==0)
		{
	        for(int i=0;i<lav;i++)
	        {
		        cout<<setw(2)<<d[i].g<<"/"<<setw(2)<<d[i].m<<"/"<<setw(4)<<d[i].anno
		        <<setw(15)<<c[i].cant
		        <<setw(15)<<c[i].citta
		        <<setw(15)<<c[i].luogo
		        <<setw(15)<<c[i].bigl
		        <<setw(10)<<c[i].cap
		        <<setw(10)<<c[i].prenotati
		        <<setw(10)<<c[i].cap-c[i].prenotati<<endl;
		        cout<<"-------------------------------"<<endl;
	        }
		}
	}
}
void scambiostring(string &x,string &y)
{
	string temp=x;
	x=y;
	y=temp;
}
void scambioint(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
void scambiofloat(float &x,float &y)
{
	float temp=x;
	x=y;
	y=temp;
}
void alfabeticocant(dataa d[],int lav,concerto c[])
{
	for(int i=0;i<lav-1;i++)
	{
		for(int j=i+1;j<lav;j++)
		{
			if(c[j].cant<c[i].cant)
			{
				scambiostring(c[i].cant,c[j].cant);
				scambiostring(c[i].citta,c[j].citta);
				scambiostring(c[i].luogo,c[j].luogo);
				scambiofloat(c[i].bigl,c[j].bigl);
				scambioint(c[i].cap,c[j].cap);
				scambioint(c[i].prenotati,c[j].prenotati);
				dataa temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	for(int i=0;i<lav;i++)
	{
		cout<<"CANTANTE:"<<c[i].cant<<endl;
		cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
		cout<<"CITTA:"<<c[i].citta<<endl;
		cout<<"LUOGO:"<<c[i].luogo<<endl;
		cout<<"PREZZO:"<<c[i].bigl<<endl;
		cout<<"CAPIENZA:"<<c[i].cap<<" PRENOTATI:"<<c[i].prenotati<<" DISPONIBILI:"<<c[i].cap-c[i].prenotati<<endl;
		cout<<"-------------------------------"<<endl;
	}
}
void prezzo(dataa d[],int lav,concerto c[])
{
	for(int i=0;i<lav-1;i++)
	{
		for(int j=i+1;j<lav;j++)
		{
			if(c[j].bigl<c[i].bigl)
			{
				scambiostring(c[i].cant,c[j].cant);
				scambiostring(c[i].citta,c[j].citta);
				scambiostring(c[i].luogo,c[j].luogo);
				scambiofloat(c[i].bigl,c[j].bigl);
				scambioint(c[i].cap,c[j].cap);
				scambioint(c[i].prenotati,c[j].prenotati);
				dataa temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	for(int i=0;i<lav;i++)
	{
		cout<<"COSTO BIGLIETTO:"<<c[i].bigl<<endl;
		cout<<"CANTANTE:"<<c[i].cant<<endl;
		cout<<"DATA:"<<d[i].g<<"/"<<d[i].m<<"/"<<d[i].anno<<endl;
		cout<<"CITTA:"<<c[i].citta<<endl;
		cout<<"LUOGO:"<<c[i].luogo<<endl;
		cout<<"CAP:"<<c[i].cap<<" PRENOTATI:"<<c[i].prenotati<<" DISPONIBILI:"<<c[i].cap-c[i].prenotati<<endl;
		cout<<"-------------------------------"<<endl;
	}
}
void aggiornati(dataa d[],int lav,concerto c[])
{
	string canta,citta;
	cout<<"Inserisci il nome del cantante:"<<endl;
	cin>>canta;
	cout<<"Inserisci la citta:"<<endl;
	cin>>citta;
	bool trovato=false;
	int i=0;
	do
	{
		if(c[i].cant==canta && c[i].citta==citta)
		{
			cout<<"Inserisci nuova data (gg mm aaaa):"<<endl;
			cin>>d[i].g>>d[i].m>>d[i].anno;
			cout<<"Inserisci nuovo luogo:"<<endl;
			cin>>c[i].luogo;
			cout<<"Inserisci nuovo prezzo:"<<endl;
			cin>>c[i].bigl;
			cout<<"Inserisci nuova capienza:"<<endl;
			cin>>c[i].cap;
			cout<<"Inserisci posti gia' prenotati:"<<endl;
			cin>>c[i].prenotati;
			trovato=true;
		}
		else i++;
	}while(trovato==false && i<lav);
	if(trovato==false) cout<<"Concerto non trovato!"<<endl;
}
void dicotomica(dataa d[],int lav,concerto c[])
{
	string cerca;
	bool trova=false;
	int sx,dx,md,pos;
	alfabeticocant(d,lav,c);
	cout<<"Inserisci il nome del cantante da cercare"<<endl;
	cin>>cerca;
	sx=0;
	dx=lav-1;
	do
	{
		md=(sx+dx)/2;
		if(c[md].cant==cerca||c[sx].cant==cerca||c[dx].cant==cerca) trova=true;
		else if(c[md].cant<cerca) sx=md+1;
		else dx=md-1;
	}while(trova==false && sx<=dx);
	if(c[md].cant==cerca) pos=md;
	if(c[sx].cant==cerca) pos=sx;
	if(c[dx].cant==cerca) pos=dx;
	if(trova==true)
	{
		cout<<"Cantante trovato"<<endl;
		cout<<"Citta:"<<c[pos].citta<<endl;
		cout<<"PREZZO:"<<c[pos].bigl<<endl;
	}
	else cout<<"Cantante non trovato"<<endl;
}
