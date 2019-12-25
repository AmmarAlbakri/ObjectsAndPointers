#include<iostream>
using namespace std;
#include<cstring>
#include<cstdlib>
class Tag{
	char *tag = "TAG";
	char *title,*artist,*year,*album,*comment;
	int genre;
	public:
	void setTitle(char* a){
		title=new char(strlen(a));
		strcpy(title,a);
	}
	void setArtist(char* a){
		artist=new char(strlen(a));
		strcpy(artist,a);
	}
	void setAlbum(char*a){
		album=new char(strlen(a));
		strcpy(album,a);
	}
	void setYear(char* a){
		year=new char(strlen(a));
		strcpy(year,a);
	}
	void setComment(char* a){
		comment=new char(strlen(a));
		strcpy(comment,a);
	}
	void setGenre(int a){
		genre=a;
	}
	char* getTitle(){
		return title;
	}
	char* getArtist(){
		return artist;
	}
	char* getAlbum(){
		return album;
	}
	char* getYear(){
		return album;
	}
	char* getComment(){
		return comment;
	}
	int getGenre(){
		return genre;
	}
	Tag(){
	//	cout<<"default kurucusu calisti"<<endl;
		title=new char[30];
		artist=new char[30];
		album=new char[30];
		year=new char[4];
		comment=new char[30];
	}
	Tag(Tag const &t){
	//	cout<<"Kopyalama kurucusu calisti"<<endl;
		int size;
    size=strlen(t.tag);
    tag=new char[size+1];
    strcpy(tag,t.tag);
    size=strlen(t.title);
    title=new char[size+1];
    strcpy(title,t.title);
    size=strlen(t.artist);
    artist=new char[size+1];
    strcpy(artist,t.artist);
    size=strlen(t.album);
    album=new char[size+1];
    strcpy(album,t.album);
    size=strlen(t.year);
    year=new char[size+1];
    strcpy(year,t.year);
    size=strlen(t.comment);
    comment=new char[size+1];
    strcpy(comment,t.comment);
	genre=t.genre;
	}
	Tag(char* a,char* b,char* c,char* d,char* e,int f){
	//	cout<<"paraetreli kurucusu calisti"<<endl;
		setTitle(a);setArtist(b);setAlbum(c);
		setYear(d);setComment(e);setGenre(f);	
	}
	~Tag(){
	//	cout<<"yok edici calisti"<<endl;
		delete[] title;delete[] artist;
		delete[] album;delete[] year;delete[] comment;
	}
	void print(){
		cout<<title<<endl<<"\tartist:"<<artist<<endl<<"\talbum:"<<album<<endl<<"\tcomment:"<<comment<<endl;
	}
	void readTag(){
		char* gString=new char[3];
		cout<<"title:";gets(title);
		cout<<"artist:";gets(artist);
		cout<<"album:";gets(album);
		cout<<"year:";gets(year);
		cout<<"comment:";gets(comment);
		cout<<"genre:";gets(gString);
		genre=atoi(gString);
	}
};
int main(){
	Tag tag1;
	tag1.setTitle("staring at the sun");
	tag1.setArtist("offspring");
	tag1.setAlbum("americana");
	tag1.setYear("1998");
	tag1.setComment("no comment");
	//tag1.print();
	Tag *tag2=new Tag(tag1);
	//tag2->print();
	Tag tag3(*tag2);
//	tag3.print();
	delete tag2;
	Tag tag4;
	tag4.readTag();
	Tag tag5;
	tag5.readTag();
	tag4.print();
	tag3.print();
	tag5.print();
	return 0;
}
