#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int canum=15,cardnum=20;
int cl,fightflag;
int bosstype,hittype;
int hp=100,hpmax=100,money=0,conf=0,confmax=20,ht=0;
int ck[5],flcard[105];
int vis[105];
int fy[105]={0,0,0,0,0,7,7,7,11,5,7,7,6,6,6,6,10,6,9,15,0};
int mmz=0,jp=0;
int speed=0;
double pg,jn,dz,xd;
int wpg,wjn,wdz;
int hh,ms;
double xx,xy,cm,bj,bs,js;
int boss=80,tboss=80,bhit=0,lspy=0;
int spywpg=0,spywjn=0,spywdz=0;
int fxy=0,fcm=0,confpos=0;
string s1; 
int radom(double x){
	int rand=(clock()-cl)%6+1;
	if(rand<=x){
		return 1;
	}else{
		return 0;
	}
}
int ca(int x){
	if(x==1){
		cout<<"������̳"<<endl; 
	}else if(x==2){
		cout<<"���Ҽ�̳"<<endl; 
	}else if(x==3){
		cout<<"��Ը�ž�"<<endl; 
	}else if(x==4){
		cout<<"�ش�����"<<endl; 
	}else if(x==5){
		cout<<"����"<<endl; 
	}else if(x==6){
		cout<<"������·"<<endl; 
	}else if(x==7){
		cout<<"������"<<endl; 
	}else if(x==8){
		cout<<"δ֪����"<<endl; 
	}else if(x==9){
		cout<<"δ֪����"<<endl;
	}else if(x==10){
		cout<<"������̳"<<endl;
	}else if(x==11){
		cout<<"����ֽ"<<endl; 
	}else if(x==12){
		cout<<"����"<<endl;
	}else if(x==13){
		cout<<"δ֪��С��"<<endl;
	}else if(x==14){
		cout<<"ף����Ʒ"<<endl;
	}else if(x==15){
		cout<<"ף����̳"<<endl;
	}
}
int listcard(int x){
	if(x==1){
		cout<<"�����е�.. 0$"<<endl;
	}else if(x==2){
		cout<<"�ɼ�. 0$"<<endl;
	}else if(x==3){
		cout<<"��.... 0$"<<endl;
	}else if(x==4){
		cout<<"һ����ɽ 0$"<<endl;
	}else if(x==5){
		cout<<"ǿ��ն�� 7$"<<endl;
	}else if(x==6){
		cout<<"ǿ��ͻ�� 7$"<<endl;
	}else if(x==7){
		cout<<"ǿ����� 7$"<<endl;
	}else if(x==8){
		cout<<"����ƽ�� 11$"<<endl;
	}else if(x==9){
		cout<<"ǿ���չ� 5$"<<endl;
	}else if(x==10){
		cout<<"���Ⱪ�� 7$"<<endl; 
	}else if(x==11){
		cout<<"��ȡ֮�� 7$"<<endl;  
	}else if(x==12){
		cout<<"����֮�� 6$"<<endl; 
	}else if(x==13){
		cout<<"��ŭ֮�� 6$"<<endl; 
	}else if(x==14){
		cout<<"̰��֮�� 6$"<<endl; 
	}else if(x==15){
		cout<<"����֮�� 6$"<<endl; 
	}else if(x==16){
		cout<<"����֮�� 10$"<<endl; 
	}else if(x==17){
		cout<<"����֮�� 6$"<<endl; 
	}else if(x==18){
		cout<<"���ٱ��� 9$"<<endl; 
	}else if(x==19){
		cout<<"ͷ������ 15$"<<endl; 
	}else if(x==20){
		cout<<"ˢ�¹��� 0$"<<endl; 
	}
} 
int printcard(int x){
	if(x==1){
		cout<<"�����е�.. 0$"<<endl;
		cout<<"�����еĳɼ���һ����ɽ,��������Ŭ�������뺳��..."<<endl;
		cout<<"����4�ſ�����3�غ��˺�"<<endl;
	}else if(x==2){
		cout<<"�ɼ�. 0$"<<endl;
		cout<<"�����еĳɼ���һ����ɽ,��������Ŭ�������뺳��..."<<endl;
		cout<<"����4�ſ�����3�غ��˺�"<<endl;
	}else if(x==3){
		cout<<"��.... 0$"<<endl;
		cout<<"�����еĳɼ���һ����ɽ,��������Ŭ�������뺳��..."<<endl;
		cout<<"����4�ſ�����3�غ��˺�"<<endl;
	}else if(x==4){
		cout<<"һ����ɽ 0$"<<endl;
		cout<<"�����еĳɼ���һ����ɽ,��������Ŭ�������뺳��..."<<endl;
		cout<<"����4�ſ�����3�غ��˺�"<<endl;
	}else if(x==5){
		cout<<"ǿ��ն�� 7$"<<endl;
		cout<<"���ն���˺�+3,��Ѫ��+10%"<<endl;
	}else if(x==6){
		cout<<"ǿ��ͻ�� 7$"<<endl;
		cout<<"���ͻ���˺�+4,������+16.7%"<<endl;
	}else if(x==7){
		cout<<"ǿ����� 7$"<<endl;
		cout<<"��Ĵ���˺�+2,ѣ����+16.7%"<<endl;
	}else if(x==8){
		cout<<"����ƽ�� 11$"<<endl;
		cout<<"���ȫ��+1,�̳�ն��ͻ�̴�����˼��ӳ�"<<endl;
	}else if(x==9){
		cout<<"ǿ���չ� 5$"<<endl;
		cout<<"����չ��˺�+2"<<endl;
	}else if(x==10){
		cout<<"���Ⱪ�� 7$"<<endl; 
		cout<<"��ı�����+16.7%,�����˺�+50%"<<endl; 
	}else if(x==11){
		cout<<"��ȡ֮�� 7$"<<endl; 
		cout<<"�����Ѫ+20%"<<endl; 
	}else if(x==12){
		cout<<"����֮�� 6$"<<endl; 
		cout<<"���ȫ��+5,���ж�����-1"<<endl; 
	}else if(x==13){
		cout<<"��ŭ֮�� 6$"<<endl; 
		cout<<"���ȫ��+3,���ٶ�-4"<<endl; 
	}else if(x==14){
		cout<<"̰��֮�� 6$"<<endl; 
		cout<<"���ȫ��+2,���ܵ��˺�+3"<<endl; 
	}else if(x==15){
		cout<<"����֮�� 6$"<<endl; 
		cout<<"���ȫ��+2,���޷�����"<<endl; 
	}else if(x==16){
		cout<<"����֮�� 10$"<<endl; 
		cout<<"�о���֮������֮��̰��֮�ַ�ŭ֮�ǿɴ���,�����为��Ч��,����+2"<<endl; 
	}else if(x==17){
		cout<<"����֮�� 6$"<<endl; 
		cout<<"��ĳ�Ĭ��+16.7%"<<endl; 
	}else if(x==18){
		cout<<"���ٱ��� 9$"<<endl; 
		cout<<"����ٶ�+2"<<endl; 
	}else if(x==19){
		cout<<"ͷ������ 15$"<<endl; 
		cout<<"���ô˿�ʱ��������+1000"<<endl; 
	}else if(x==20){
		cout<<"ˢ�¹��� 0$"<<endl; 
		cout<<"������ʱ��������ˢ��"<<endl; 
	}     
}
int fightinit(){
	xd=2;
	speed=0;
	pg=ht+1,jn=ht+2,dz=ht+5;
	wpg=0,wjn=0,wdz=0;
	hh=0,ms=0;
	xx=0.0,xy=0,cm=0,bj=0,bs=2.0,js=0.0;
	if(vis[1] && vis[2] && vis[3] && vis[4]){
		ms=3;
		vis[1]=vis[2]=vis[3]=vis[4]=0;
		cout<<"�����еĳɼ���һ����ɽ,��������Ŭ�������뺳��..."<<endl;
		cout<<"����3�غ��˺�"<<endl;
	}
	if(vis[5]){
		if(vis[8] || hittype==1){
			pg+=3;
			jn+=3;
			dz+=3;
			xx+=0.1;
		}
	}
	if(vis[6]){
		if(vis[8] || hittype==2){
			pg+=4;
			jn+=4;
			dz+=4;
			bj+=1;
		}
	}
	if(vis[7]){
		if(vis[8] || hittype==3){
			pg+=2;
			jn+=2;
			dz+=2;
			xy++;
		}
	}
	if(vis[8]){
		pg++;
		jn++;
		dz++;
	}
	if(vis[9]){
		pg+=2;
	}
	if(vis[10]){
		bj++;
		bs+=0.5;
	}
	if(vis[11]){
		xx+=0.2;
	}
	if(vis[12]){
		if(!(vis[13] && vis[14] && vis[15] && vis[16])){
			xd--;
		}
		pg+=5;
		jn+=5;
		dz+=5;
	}
	if(vis[13]){
		if(!(vis[12] && vis[14] && vis[15] && vis[16])){
			speed-=4;
		}
		pg+=3;
		jn+=3;
		dz+=3;
	}
	if(vis[14]){
		if(!(vis[12] && vis[13] && vis[15] && vis[16])){
			js-=3;
		}
		pg+=2;
		jn+=2;
		dz+=2;
	}
	if(vis[15]){
		if(!(vis[12] && vis[13] && vis[14] && vis[16])){
			bj=-1e9;
		}
		pg+=2;
		jn+=2;
		dz+=2;
	}
	if(vis[17]){
		cm++;
	}
	if(vis[18]){
		speed+=2;
	}
	if(vis[19]){
		confmax+=1000;
	}
}
int fightspy(){
	int sh=0;
	for(int i=1;i<=2;i++){
		if(spywpg<=0 && hh>ms){
			spywpg=1;
			cout<<"bossʹ����bite"<<endl;
			sh+=4+bhit-js;
			conf++; 
		}else if(spywjn<=0 && fcm<=0){
			spywjn=2; 
			cout<<"boss�ٻ�С֩��"<<endl;
			lspy++;
		}else if(spywdz<=0 && hh>ms && conf>=6 && fcm<=0){
			spywdz=4;
			cout<<"bossʹ����ħ�ɻ�"<<endl;
			int tmp=(clock()-cl)%3+3;
			cout<<"����Ϊ:"<<tmp<<endl;
			sh+=(6+bhit+conf-js)*tmp;
			conf+=tmp;
		}
		Sleep(1000);
	} 
	if(lspy>0 && hh>ms){
		cout<<"С֩��ʹ����bite"<<endl;
		sh+=2*(lspy-js);
		conf+=lspy;
	}
	if(confpos>0){
		sh*=2;
	}
	hp-=sh;
}
int card(int x){
	if(x==1){
		cout<<"Ѫ��+10,Ѫ������+10"<<endl; 
		Sleep(1000);
		hp+=10,hpmax+=10;
	}else if(x==2){
		cout<<"��û�л���ֵ,��������+4,�������ֵ-6"<<endl; 
		Sleep(1000);
		if(conf==0){
			cout<<"��������+4"<<endl; 
			confmax+=4;
		}else{
			cout<<"����ֵ-6"<<endl; 
			conf=max(0,conf-6);
		}
	}else if(x==3){
		for(int i=1;i<=cardnum;i++){
			if(!vis[i]){
				cout<<i<<":";
				listcard(i);
				Sleep(200);
			}
		}
		Sleep(1000);
		cout<<"��ѡ����"<<endl;
		int r;
		cin>>r;
		while(r<1 || r>cardnum){
			cout<<"������ѡ��"<<endl;
			cin>>r;
		}
		vis[r]=1;
		printcard(r);
	}else if(x==4){ 
		cout<<"Ѫ��-10"<<endl; 
		Sleep(1000);
		hp-=10;
	}else if(x==5){
		cout<<"����"<<endl; 
		Sleep(1000);
		cout<<"1-5:����+1-5,6:��+1"<<endl;
		Sleep(1000);
		int rand=(clock()-cl)%6+1;
		cout<<"��ĵ�����:";
		Sleep(1000);
		cout<<rand<<endl;
		if(rand==6){
			cout<<"����һ�ſ�"<<endl;
			cout<<"������:";
			Sleep(1000);
			int rand=(clock()-cl)%cardnum+1;
			while(vis[rand]){
				rand=(clock()-cl)%cardnum+1;
			} 
			printcard(rand);
			vis[rand]=1;
		}else{
			cout<<"������"<<rand<<"�����"<<endl; 
			money+=rand;
		}
	}else if(x==6){
		cout<<"������·"<<endl; 
		cout<<"�������˼�����·,�Ƿ�Ѱ�ҿ���"<<endl; 
		Sleep(1000);
		cout<<"1:��Ѱ��,�ܵ�12���˺�"<<endl;
		cout<<"2:Ѱ��,1-4:�ܵ�20���˺�,5-6:����+3"<<endl;
		Sleep(1000);
		int r;
		cin>>r;
		while(r!=1 && r!=2){
			cout<<"������ѡ��"<<endl;
			cin>>r;
		}
		if(r==1){
			cout<<"�ܵ�12���˺�"<<endl;
			hp-=12;
		}else{
			int rand=(clock()-cl)%6+1;
			cout<<"��ĵ�����:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=5){
				cout<<"����3�����"<<endl;
				money+=3;
			}else{
				cout<<"�ܵ�20���˺�"<<endl;
				hp-=20;
			}
		}
	}else if(x==7){
		cout<<"������"<<endl; 
		cout<<"1-2:��-1,3-6:�ܵ�10���˺�"<<endl;
		Sleep(1000);
		int rand=(clock()-cl)%6+1;
		cout<<"��ĵ�����:";
		Sleep(1000);
		cout<<rand<<endl;
		if(rand<=2){
			int fl=0;
			for(int i=1;i<=cardnum;i++){
				if(vis[i]==1){
					fl=1;
					break;
				}
			}
			if(fl==0){
				cout<<"��û�п�"<<endl;
				Sleep(1000);
			}else{
				cout<<"����ʧһ�ſ�"<<endl;
				cout<<"����ʧ��:";
				Sleep(1000);
				int rand=(clock()-cl)%cardnum+1;
				while(!vis[rand]){
					rand=(clock()-cl)%cardnum+1;
				} 
				printcard(rand);
				vis[rand]=0;
			}
		}else{
			cout<<"�ܵ�10���˺�"<<endl;
			hp-=10;
		}
	}else if(x==8){
		cout<<"����һ�ſ���"<<endl; 
		cout<<"������:";
		Sleep(1000);
		int rand=(clock()-cl)%cardnum+1;
		while(vis[rand]){
			rand=(clock()-cl)%cardnum+1;
		} 
		printcard(rand);
		vis[rand]=1;
	}else if(x==9){
		cout<<"����һ�ſ���"<<endl;
		cout<<"������:";
		Sleep(1000);
		int rand=(clock()-cl)%cardnum+1;
		while(vis[rand]){
			rand=(clock()-cl)%cardnum+1;
		} 
		printcard(rand);
		vis[rand]=1;
	}else if(x==10){
		cout<<"������+1"<<endl; 
		Sleep(1000);
		ht++;
	}else if(x==11){
		cout<<"���ҵ�������ֽ"<<endl;
		cout<<"�ƺ�����������ĳ������"<<endl;
		mmz++;
	}else if(x==12){
		cout<<"�������˴���"<<endl;
		cout<<"�ƺ���Ҫ��������"<<endl;
		Sleep(1000);
		if(mmz>0){
			mmz--;
			cout<<"������ȷ!"<<endl;
			Sleep(1000);
			cout<<"1-3:����+12-14,4-6:��+2-4"<<endl;
			Sleep(1000);
			int rand=(clock()-cl)%6+1;
			cout<<"��ĵ�����:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=4){
				cout<<"����"<<rand-2<<"�ſ�"<<endl;
				cout<<"������:";
				for(int i=1;i<=rand-2;i++){
					Sleep(1000);
					int rand=(clock()-cl)%cardnum+1;
					while(vis[rand]){
						rand=(clock()-cl)%cardnum+1;
					} 
					printcard(rand);
					vis[rand]=1;
				}
			}else{
				cout<<"������"<<rand+12<<"�����"<<endl; 
				money+=rand+12;
			}
		}else{
			cout<<"ȱ������"<<endl;
		}
	}else if(x==13){
		cout<<"��������δ֪��С��"<<endl;
		Sleep(1000);
		cout<<"1:����,1-2:���·���,3-6:��+1"<<endl;
		cout<<"2:����,1-3:�ظ�20��Ѫ��,4-6:������+1"<<endl;
		Sleep(1000);
		int r;
		cin>>r; 
		while(r!=1 && r!=2){
			cout<<"������ѡ��"<<endl;
			cin>>r;
		}
		if(r==1){
			int rand=(clock()-cl)%6+1;
			cout<<"��ĵ�����:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=3){
				cout<<"��Ŀ�+1"<<endl;
				cout<<"����һ�ſ���"<<endl; 
				cout<<"������:";
				Sleep(1000);
				int rand1=(clock()-cl)%cardnum+1;
				while(vis[rand1]){
					rand1=(clock()-cl)%cardnum+1;
				} 
				printcard(rand1);
				vis[rand1]=1;
			}else{
				cout<<"���·���"<<endl;
			}
		}else{
			int rand=(clock()-cl)%6+1;
			cout<<"��ĵ�����:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=4){
				cout<<"�㹥����+1"<<endl;
				ht++;
			}else{
				cout<<"��ظ�20��Ѫ��"<<endl;
				hp+=20;
			}
		}
	}else if(x==14){
		cout<<"���ҵ���ף����Ʒ"<<endl;
		cout<<"�ƺ�������ĳ����̳��"<<endl;
		jp++;
	}else if(x==15){
		cout<<"��������ף����̳"<<endl;
		cout<<"�ƺ���Ҫ�׳���Ʒ"<<endl;
		Sleep(1000);
		if(jp>0){
			jp--;
			cout<<"�׼��ɹ�!"<<endl;
			Sleep(1000);
			cout<<"1-2:Ѫ��+40,3-4:������+3,5-6:���2-3�ſ�"<<endl;
			Sleep(1000);
			int rand=(clock()-cl)%6+1;
			cout<<"��ĵ�����:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand<=2){
				hp+=40;
			}else if(rand<=4){
				ht+=3;
			}else{
				cout<<"����"<<rand-3<<"�ſ�"<<endl;
				cout<<"������:";
				for(int i=1;i<=rand-3;i++){
					Sleep(1000);
					int rand=(clock()-cl)%cardnum+1;
					while(vis[rand]){
						rand=(clock()-cl)%cardnum+1;
					} 
					printcard(rand);
					vis[rand]=1;
				}
			}
		}else{
			cout<<"��Ʒ����"<<endl;
		}
	}
}
int main(){
	int r,css=0,hitmax=65535;
	cout<<"Loading...";
	Sleep(3000);
	system("CLS");
	cout<<"�����뿨��"<<endl;
	Sleep(3000);
	system("CLS");
	cout<<"��ѡ����ս��boss:"<<endl;
	Sleep(1000);
	cout<<"1:֩����"<<endl;
	cin>>bosstype;
	cl=clock();
	while(bosstype!=1){
		cout<<"������ѡ��"<<endl;
		cin>>bosstype;
	}
	Sleep(1000);
	cout<<"��ѡ����Ĺ�������:"<<endl;
	cout<<"1:ն��   2:ͻ��   3:���"<<endl;
	cin>>hittype;
	while(hittype<1 || hittype>3){
		cout<<"������ѡ��"<<endl;
		cin>>hittype;
	}
	cout<<"ѡ��ɹ�,��ʼ����"<<endl;
	for(int tfl=1;tfl<=4;tfl++){ 
		if(tfl>=2){
			hitmax=20;
		}
		Sleep(2000);
		system("CLS");
		for(int i=1;i<=10;i++){
			css++;
			cout<<"��"<<css<<"��:"<<endl;
			money++;
			cout<<"hp:"<<hp<<" money:"<<money<<endl;
			cout<<"��ѡ����:1,2,3"<<endl;
			cin>>r;
			while(r!=1 && r!=2 && r!=3){
				cout<<"������ѡ��"<<endl;
				cin>>r;
			}
			cout<<"��ѡ����";
			ck[1]=(clock()-cl)%canum+1;
			ck[2]=ck[1];
			ck[3]=ck[1];
			ca(ck[1]);
			int tmp=1;
			for(int i=1;i<=3;i++){
				if(i!=r){
					tmp++;
					Sleep(1000);
					cout<<"��"<<i<<"����:"; 
					while(ck[tmp]==ck[1] || ck[tmp]==ck[tmp-1]){
						ck[tmp]=(clock()-cl)%canum+1;
					}
					ca(ck[tmp]);
				}
			}
			Sleep(1000);
			cout<<endl;
			card(ck[1]);
			Sleep(1000);
			cout<<endl;
			cout<<"�����������ַ�����"<<endl;
			string sr;
			cin>>sr;
			cout<<endl;
			cout<<"��������������������������������������������������������"<<endl;
			cout<<endl; 
			if(hp<=0){
				cout<<"��ʧ����,�÷�:0"<<endl;
				return 0; 
			}
		}
		cout<<"�Ƿ���̵�"<<endl;
		cout<<"1:�� 2:����"<<endl; 
		cin>>r;
		while(r!=1 && r!=2){
			cout<<"������ѡ��"<<endl;
			cin>>r;
		}
		if(r==1){
			money-=2; 
			cout<<"���̵�"<<endl;
			while(true){
				if(fightflag){
					cout<<"ս��ǰ׼��"<<endl;
					break;
				}
				for(int j=1;j<=cardnum;j++){
					flcard[j]=0;
				}
				for(int i=1;i<=6;i++){
					int rand=(clock()-cl)%cardnum+1;
					int fla=0;
					for(int j=1;j<i;j++){
						if(flcard[j]==rand){
							fla=1;
						}
					}
					while(vis[rand] || fla){
						rand=(clock()-cl)%cardnum+1;
						fla=0;
						for(int j=1;j<i;j++){
							if(flcard[j]==rand){
								fla=1;
							}
						}
					}
					cout<<"��"<<i<<"�ſ���:"<<endl;
					printcard(rand);
					flcard[i]=rand;
					if(rand==20){
						vis[20]=1; 
					} 
					Sleep(1000);
					cout<<endl; 
				}
				while(true){
					cout<<"�㻹��"<<money<<"�����"<<endl;
					cout<<endl;
					if(fightflag){
						break;
					}
					cout<<"1-6:����1-6�ſ�,7:ˢ��"<<endl;
					int r;
					cin>>r;
					while(r<1 && r>7){
						cout<<"������ѡ��"<<endl;
						cin>>r;
					}
					if(r==7){
						if(money>=2 && vis[20]==0){
							cout<<"ˢ�³ɹ�"<<endl;
							money-=2;
							break;
						}else{
							if(vis[20]!=0){
								cout<<"���ò���,��ʼս��"<<endl;
								fightflag=1;
								break;
							}else{
								cout<<"ˢ�¹���"<<endl;
							}
						}	
					}else{
						if(money>=fy[flcard[r]]){
							money-=fy[flcard[r]];
							vis[flcard[r]]=1;
							cout<<"����ɹ�,�㻹��"<<money<<"�����"<<endl;
							printcard(flcard[r]);
						}else{
							cout<<"���ò���"<<endl;
						}
						cout<<"1:ˢ�� 2:��ʼս��"<<endl;
						int r;
						cin>>r;
						while(r<1 && r>2){
							cout<<"������ѡ��"<<endl;
							cin>>r;
						}
						if(r==1){
							if(money>=2){
								cout<<"ˢ�³ɹ�"<<endl;
								money-=2;
								break;
							}else{
								cout<<"ˢ��ʧ��,��ʼս��"<<endl;
								fightflag=1;
								break;
							}
						}else{
							cout<<"ս��ǰ׼��"<<endl;
							fightflag=1;
						}
					}
				}
				vis[20]=0;
			}
		}else{
			cout<<"ս��ǰ׼��"<<endl;
		}
		cout<<"��Ŀ�����"<<endl;
		for(int i=1;i<=cardnum;i++){
			if(vis[i]){
				printcard(i);
				Sleep(1000);
				cout<<endl;
			}
		}
		fightinit();
		if(hp>hpmax){
			hp=hpmax;
		}
		cout<<"����������:"<<ht<<endl;
		cout<<"����������:"<<js<<endl;
		cout<<"Ѫ��:"<<hp<<endl;
		cout<<"Ѫ������:"<<hpmax<<endl;
		cout<<"����ֵ:"<<conf<<endl;
		cout<<"��������:"<<confmax<<endl;
		cout<<"������:"<<bj*16.7<<"%"<<endl;
		cout<<"�����˺�:"<<bs*100.0<<"%"<<endl;
		cout<<"ѣ����:"<<xy*16.7<<"%"<<endl;
		cout<<"��Ѫ��:"<<xx*100<<"%"<<endl;
		cout<<"��Ĭ��:"<<cm*16.7<<"%"<<endl;
		cout<<"�����ٶ�:"<<speed<<endl;
		cout<<"�չ��˺�:"<<pg<<endl;
		cout<<"�����˺�:"<<jn<<endl;
		cout<<"�����˺�:"<<dz<<endl;
		cout<<"���������ַ���ս��"<<endl;
		cin>>s1;
		Sleep(1000);
		cout<<"��ʼս��"<<endl;
		int rr;
		while(true){
			if(hp>hpmax){
				hp=hpmax;
			}
			hh++;
			cout<<"��"<<hh<<"�غ�"<<endl;
			cout<<"Ѫ��:"<<hp<<"   ����ֵ:"<<conf<<endl;
			cout<<"bossѪ��"<<boss<<endl;
			cout<<endl;
			int spfl=0;
			int mysp=0,spysp=0;
			while(mysp==spysp){
				cout<<"����ٶ�:";
				mysp=(clock()-cl)%6+1+speed;
				Sleep(1000);
				cout<<mysp<<endl;
				Sleep(1000);
				cout<<"���ǵ��ٶ�:";
				spysp=(clock()-cl-mysp)%6+1;
				Sleep(1000);
				cout<<spysp<<endl;
			}
			if(mysp<spysp){
				spfl=1;
			}else{
				spfl=2;
			}
			wpg--;
			wjn--;
			wdz--;
			spywpg--;
			spywjn--;
			spywdz--;
			fxy--;
			fcm--;
			confpos--;
			if(spfl==1){
				cout<<"boss�ж�"<<endl;
				cout<<endl;
				if(fxy>0){
					cout<<"boss��ѣ��"<<endl;
				}else{
					fightspy();
				}
			}
			if(hp<0){
				cout<<"��ʧ����,�÷�:"<<boss<<endl;
				Sleep(5000);
				return 0;
			}
			int txd=xd;
			if(conf>confmax && confpos<0){
				confpos=2;
			}
			if(confpos>0){
				txd=0;
				cout<<"���ѱ�����"<<endl;
			}
			if(confpos==0){
				conf=0;
			}
			int tflag=0;
			for(int i=1;i<=txd;i++){
				int sh=0;
				int cs=1; 
				cout<<"1:�չ� 2:���� 3:���� ����:������"<<endl;
				cin>>rr;
				if(rr==1){
					if(wpg<=0){
						sh=pg;
						wpg=1; 
					}else{
						cout<<"������ȴ"<<endl;
						i--;
						cs=0;
					}
				}
				if(rr==2){
					if(wjn<=0){
						sh=jn;
						wjn=2; 
					}else{
						cout<<"������ȴ"<<endl;
						i--;
						cs=0;
					}
				}
				if(rr==3){
					if(wdz<=0){
						sh=dz;
						wdz=4;
					}else{
						cout<<"������ȴ"<<endl;
						i--;
						cs=0;
					}
				}
				if((rr==1 || rr==2 || rr==3) && cs){
					if(bj>0){
						cout<<"�Ƿ񱩻�:����";
						if(radom(bj)){
							cout<<"�ɹ�"<<endl;
							sh*=bs;
						}else{
							cout<<"ʧ��"<<endl;
						}
					}
					if(xy>0){
						cout<<"�Ƿ�ѣ��:ѣ��";
						if(radom(xy)){
							cout<<"�ɹ�"<<endl;
							fxy=1;
							if(spfl==1){
								fxy++;
							}
						}else{
							cout<<"ʧ��"<<endl;
						}
					}
					if(cm>0){
						cout<<"�Ƿ��Ĭ:��Ĭ";
						if(radom(cm)){
							cout<<"�ɹ�"<<endl;
							fcm=1;
							if(spfl==1){
								fcm++;
							}
						}else{
							cout<<"ʧ��"<<endl;
						}
					}
					boss-=min(sh,hitmax);
					hp+=min(sh,hitmax)*xx;
					if(sh==0){
						cout<<"δ����˺�"<<endl;
					}
					if(sh>100){
						cout<<"ȫ��һ��!"<<endl;
					}
					if(sh>1000){
						cout<<"����˳ɾ�:ȫ��һ��!!!";
					}
				}
				cout<<"bossѪ��"<<boss<<endl;
				Sleep(1000);
				cout<<endl;
				if(boss<=0){
					cout<<"��Ӯ��"<<endl;
					Sleep(3000);
					cout<<"��Ŀ�����"<<endl;
					for(int i=1;i<=cardnum;i++){
						if(vis[i]){
							printcard(i);
							Sleep(1000);
							cout<<endl;
						}
					}
					cout<<"����������:"<<ht<<endl;
					cout<<"����������:"<<js<<endl;
					cout<<"Ѫ��:"<<hp<<endl;
					cout<<"Ѫ������:"<<hpmax<<endl;
					cout<<"����ֵ:"<<conf<<endl;
					cout<<"��������:"<<confmax<<endl;
					cout<<"������:"<<bj*16.7<<"%"<<endl;
					cout<<"�����˺�:"<<bs*100.0<<"%"<<endl;
					cout<<"ѣ����:"<<xy*16.7<<"%"<<endl;
					cout<<"��Ѫ��:"<<xx*100<<"%"<<endl;
					cout<<"��Ĭ��:"<<cm*16.7<<"%"<<endl;
					cout<<"�����ٶ�:"<<speed<<endl;
					cout<<"�չ��˺�:"<<pg<<endl;
					cout<<"�����˺�:"<<jn<<endl;
					cout<<"�����˺�:"<<dz<<endl;
					cout<<"�����������ַ�����"<<endl;
					string ss;
					cin>>ss;
					tboss+=20;
					boss=tboss;
					lspy=0;
					hp+=30; 
					cout<<"����һ�ſ���"<<endl; 
					cout<<"������:";
					Sleep(1000);
					int rand1=(clock()-cl)%cardnum+1;
					while(vis[rand1]){
						rand1=(clock()-cl)%cardnum+1;
					} 
					printcard(rand1);
					vis[rand1]=1;
					tflag=1;
					break;
				}
			}
			if(tflag==1){
				break;
			}
			if(spfl==2){
				cout<<"boss�ж�"<<endl;
				cout<<endl;
				if(fxy>0){
					cout<<"boss��ѣ��"<<endl;
				}else{
					fightspy();
				}
			}
			if(hp<0){
				cout<<"��ʧ����,�÷�:"<<boss<<endl;
				Sleep(5000);
				string ss;
				cin>>ss;
				return 0;
			}
			cout<<"��������������������������������������������������������"<<endl; 
		}
		bhit+=2;
	}
	cout<<"ͨ��!"<<endl; 
	Sleep(10000); 
	return 0;
} 
