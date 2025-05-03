 #include<iostream>
 using namespace std;
class item
 {
    public:
 static int count; //count is static
 int number; 
public:
 void getdata(int a){
 number=a; 
count++;
 }
 void getcount(void)
 {
 cout<<"count:"; 
cout<<count<<"\n";
 }
 };
//  int item :: count ;
 int main( )
 {
 item a,b,c;
 a.getcount( );
 b.getcount( );
 c.getcount( );
 a.getdata(5);

b.getdata(10); 
c.getdata(15);
 cout<<"after reading data: "<<"\n";
 a.getcount( );
 b.getcount( );
 c.getcount( ); 

 cout<<"\n\n";
 cout<<a.count<<"\n";
return(0);



 }