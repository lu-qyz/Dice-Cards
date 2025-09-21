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
		cout<<"生命祭坛"<<endl; 
	}else if(x==2){
		cout<<"混乱祭坛"<<endl; 
	}else if(x==3){
		cout<<"祈愿古卷"<<endl; 
	}else if(x==4){
		cout<<"地刺陷阱"<<endl; 
	}else if(x==5){
		cout<<"宝箱"<<endl; 
	}else if(x==6){
		cout<<"激光阻路"<<endl; 
	}else if(x==7){
		cout<<"恶鬼灯烛"<<endl; 
	}else if(x==8){
		cout<<"未知卡牌"<<endl; 
	}else if(x==9){
		cout<<"未知卡牌"<<endl;
	}else if(x==10){
		cout<<"力量祭坛"<<endl;
	}else if(x==11){
		cout<<"密码纸"<<endl; 
	}else if(x==12){
		cout<<"大金柜"<<endl;
	}else if(x==13){
		cout<<"未知的小屋"<<endl;
	}else if(x==14){
		cout<<"祝福祭品"<<endl;
	}else if(x==15){
		cout<<"祝福祭坛"<<endl;
	}
}
int listcard(int x){
	if(x==1){
		cout<<"人心中的.. 0$"<<endl;
	}else if(x==2){
		cout<<"成见. 0$"<<endl;
	}else if(x==3){
		cout<<"是.... 0$"<<endl;
	}else if(x==4){
		cout<<"一座大山 0$"<<endl;
	}else if(x==5){
		cout<<"强化斩击 7$"<<endl;
	}else if(x==6){
		cout<<"强化突刺 7$"<<endl;
	}else if(x==7){
		cout<<"强化打击 7$"<<endl;
	}else if(x==8){
		cout<<"三相平衡 11$"<<endl;
	}else if(x==9){
		cout<<"强化普攻 5$"<<endl;
	}else if(x==10){
		cout<<"额外暴击 7$"<<endl; 
	}else if(x==11){
		cout<<"汲取之刃 7$"<<endl;  
	}else if(x==12){
		cout<<"绝望之心 6$"<<endl; 
	}else if(x==13){
		cout<<"愤怒之角 6$"<<endl; 
	}else if(x==14){
		cout<<"贪婪之手 6$"<<endl; 
	}else if(x==15){
		cout<<"憎恶之眼 6$"<<endl; 
	}else if(x==16){
		cout<<"虚无之梦 10$"<<endl; 
	}else if(x==17){
		cout<<"奥术之力 6$"<<endl; 
	}else if(x==18){
		cout<<"飞速奔跑 9$"<<endl; 
	}else if(x==19){
		cout<<"头脑清晰 15$"<<endl; 
	}else if(x==20){
		cout<<"刷新故障 0$"<<endl; 
	}
} 
int printcard(int x){
	if(x==1){
		cout<<"人心中的.. 0$"<<endl;
		cout<<"人心中的成见是一座大山,任你怎样努力都休想撼动..."<<endl;
		cout<<"集齐4张可免疫3回合伤害"<<endl;
	}else if(x==2){
		cout<<"成见. 0$"<<endl;
		cout<<"人心中的成见是一座大山,任你怎样努力都休想撼动..."<<endl;
		cout<<"集齐4张可免疫3回合伤害"<<endl;
	}else if(x==3){
		cout<<"是.... 0$"<<endl;
		cout<<"人心中的成见是一座大山,任你怎样努力都休想撼动..."<<endl;
		cout<<"集齐4张可免疫3回合伤害"<<endl;
	}else if(x==4){
		cout<<"一座大山 0$"<<endl;
		cout<<"人心中的成见是一座大山,任你怎样努力都休想撼动..."<<endl;
		cout<<"集齐4张可免疫3回合伤害"<<endl;
	}else if(x==5){
		cout<<"强化斩击 7$"<<endl;
		cout<<"你的斩击伤害+3,吸血率+10%"<<endl;
	}else if(x==6){
		cout<<"强化突刺 7$"<<endl;
		cout<<"你的突刺伤害+4,暴击率+16.7%"<<endl;
	}else if(x==7){
		cout<<"强化打击 7$"<<endl;
		cout<<"你的打击伤害+2,眩晕率+16.7%"<<endl;
	}else if(x==8){
		cout<<"三相平衡 11$"<<endl;
		cout<<"你的全伤+1,继承斩击突刺打击加伤及加成"<<endl;
	}else if(x==9){
		cout<<"强化普攻 5$"<<endl;
		cout<<"你的普攻伤害+2"<<endl;
	}else if(x==10){
		cout<<"额外暴击 7$"<<endl; 
		cout<<"你的暴击率+16.7%,暴击伤害+50%"<<endl; 
	}else if(x==11){
		cout<<"汲取之刃 7$"<<endl; 
		cout<<"你的吸血+20%"<<endl; 
	}else if(x==12){
		cout<<"绝望之心 6$"<<endl; 
		cout<<"你的全伤+5,但行动次数-1"<<endl; 
	}else if(x==13){
		cout<<"愤怒之角 6$"<<endl; 
		cout<<"你的全伤+3,但速度-4"<<endl; 
	}else if(x==14){
		cout<<"贪婪之手 6$"<<endl; 
		cout<<"你的全伤+2,但受到伤害+3"<<endl; 
	}else if(x==15){
		cout<<"憎恶之眼 6$"<<endl; 
		cout<<"你的全伤+2,但无法暴击"<<endl; 
	}else if(x==16){
		cout<<"虚无之梦 10$"<<endl; 
		cout<<"有绝望之心憎恶之眼贪婪之手愤怒之角可触发,抵消其负面效果,免伤+2"<<endl; 
	}else if(x==17){
		cout<<"奥术之力 6$"<<endl; 
		cout<<"你的沉默率+16.7%"<<endl; 
	}else if(x==18){
		cout<<"飞速奔跑 9$"<<endl; 
		cout<<"你的速度+2"<<endl; 
	}else if(x==19){
		cout<<"头脑清晰 15$"<<endl; 
		cout<<"你获得此卡时混乱上限+1000"<<endl; 
	}else if(x==20){
		cout<<"刷新故障 0$"<<endl; 
		cout<<"你遇到时不可主动刷新"<<endl; 
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
		cout<<"人心中的成见是一座大山,任你怎样努力都休想撼动..."<<endl;
		cout<<"免疫3回合伤害"<<endl;
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
			cout<<"boss使用了bite"<<endl;
			sh+=4+bhit-js;
			conf++; 
		}else if(spywjn<=0 && fcm<=0){
			spywjn=2; 
			cout<<"boss召唤小蜘蛛"<<endl;
			lspy++;
		}else if(spywdz<=0 && hh>ms && conf>=6 && fcm<=0){
			spywdz=4;
			cout<<"boss使用蛛魔噬魂"<<endl;
			int tmp=(clock()-cl)%3+3;
			cout<<"次数为:"<<tmp<<endl;
			sh+=(6+bhit+conf-js)*tmp;
			conf+=tmp;
		}
		Sleep(1000);
	} 
	if(lspy>0 && hh>ms){
		cout<<"小蜘蛛使用了bite"<<endl;
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
		cout<<"血量+10,血量上限+10"<<endl; 
		Sleep(1000);
		hp+=10,hpmax+=10;
	}else if(x==2){
		cout<<"若没有混乱值,混乱上限+4,否则混乱值-6"<<endl; 
		Sleep(1000);
		if(conf==0){
			cout<<"混乱上限+4"<<endl; 
			confmax+=4;
		}else{
			cout<<"混乱值-6"<<endl; 
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
		cout<<"请选择卡牌"<<endl;
		int r;
		cin>>r;
		while(r<1 || r>cardnum){
			cout<<"请重新选择"<<endl;
			cin>>r;
		}
		vis[r]=1;
		printcard(r);
	}else if(x==4){ 
		cout<<"血量-10"<<endl; 
		Sleep(1000);
		hp-=10;
	}else if(x==5){
		cout<<"宝箱"<<endl; 
		Sleep(1000);
		cout<<"1-5:费用+1-5,6:卡+1"<<endl;
		Sleep(1000);
		int rand=(clock()-cl)%6+1;
		cout<<"你的点数是:";
		Sleep(1000);
		cout<<rand<<endl;
		if(rand==6){
			cout<<"你获得一张卡"<<endl;
			cout<<"你获得了:";
			Sleep(1000);
			int rand=(clock()-cl)%cardnum+1;
			while(vis[rand]){
				rand=(clock()-cl)%cardnum+1;
			} 
			printcard(rand);
			vis[rand]=1;
		}else{
			cout<<"你获得了"<<rand<<"点费用"<<endl; 
			money+=rand;
		}
	}else if(x==6){
		cout<<"激光阻路"<<endl; 
		cout<<"你遇到了激光阻路,是否寻找开关"<<endl; 
		Sleep(1000);
		cout<<"1:不寻找,受到12点伤害"<<endl;
		cout<<"2:寻找,1-4:受到20点伤害,5-6:费用+3"<<endl;
		Sleep(1000);
		int r;
		cin>>r;
		while(r!=1 && r!=2){
			cout<<"请重新选择"<<endl;
			cin>>r;
		}
		if(r==1){
			cout<<"受到12点伤害"<<endl;
			hp-=12;
		}else{
			int rand=(clock()-cl)%6+1;
			cout<<"你的点数是:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=5){
				cout<<"你获得3点费用"<<endl;
				money+=3;
			}else{
				cout<<"受到20点伤害"<<endl;
				hp-=20;
			}
		}
	}else if(x==7){
		cout<<"恶鬼灯烛"<<endl; 
		cout<<"1-2:卡-1,3-6:受到10点伤害"<<endl;
		Sleep(1000);
		int rand=(clock()-cl)%6+1;
		cout<<"你的点数是:";
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
				cout<<"你没有卡"<<endl;
				Sleep(1000);
			}else{
				cout<<"你损失一张卡"<<endl;
				cout<<"你损失了:";
				Sleep(1000);
				int rand=(clock()-cl)%cardnum+1;
				while(!vis[rand]){
					rand=(clock()-cl)%cardnum+1;
				} 
				printcard(rand);
				vis[rand]=0;
			}
		}else{
			cout<<"受到10点伤害"<<endl;
			hp-=10;
		}
	}else if(x==8){
		cout<<"你获得一张卡牌"<<endl; 
		cout<<"你获得了:";
		Sleep(1000);
		int rand=(clock()-cl)%cardnum+1;
		while(vis[rand]){
			rand=(clock()-cl)%cardnum+1;
		} 
		printcard(rand);
		vis[rand]=1;
	}else if(x==9){
		cout<<"你获得一张卡牌"<<endl;
		cout<<"你获得了:";
		Sleep(1000);
		int rand=(clock()-cl)%cardnum+1;
		while(vis[rand]){
			rand=(clock()-cl)%cardnum+1;
		} 
		printcard(rand);
		vis[rand]=1;
	}else if(x==10){
		cout<<"攻击力+1"<<endl; 
		Sleep(1000);
		ht++;
	}else if(x==11){
		cout<<"你找到了密码纸"<<endl;
		cout<<"似乎是用来开启某个金柜的"<<endl;
		mmz++;
	}else if(x==12){
		cout<<"你遇到了大金柜"<<endl;
		cout<<"似乎需要输入密码"<<endl;
		Sleep(1000);
		if(mmz>0){
			mmz--;
			cout<<"密码正确!"<<endl;
			Sleep(1000);
			cout<<"1-3:费用+12-14,4-6:卡+2-4"<<endl;
			Sleep(1000);
			int rand=(clock()-cl)%6+1;
			cout<<"你的点数是:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=4){
				cout<<"你获得"<<rand-2<<"张卡"<<endl;
				cout<<"你获得了:";
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
				cout<<"你获得了"<<rand+12<<"点费用"<<endl; 
				money+=rand+12;
			}
		}else{
			cout<<"缺少密码"<<endl;
		}
	}else if(x==13){
		cout<<"你遇到了未知的小屋"<<endl;
		Sleep(1000);
		cout<<"1:进入,1-2:无事发生,3-6:卡+1"<<endl;
		cout<<"2:观望,1-3:回复20点血量,4-6:攻击力+1"<<endl;
		Sleep(1000);
		int r;
		cin>>r; 
		while(r!=1 && r!=2){
			cout<<"请重新选择"<<endl;
			cin>>r;
		}
		if(r==1){
			int rand=(clock()-cl)%6+1;
			cout<<"你的点数是:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=3){
				cout<<"你的卡+1"<<endl;
				cout<<"你获得一张卡牌"<<endl; 
				cout<<"你获得了:";
				Sleep(1000);
				int rand1=(clock()-cl)%cardnum+1;
				while(vis[rand1]){
					rand1=(clock()-cl)%cardnum+1;
				} 
				printcard(rand1);
				vis[rand1]=1;
			}else{
				cout<<"无事发生"<<endl;
			}
		}else{
			int rand=(clock()-cl)%6+1;
			cout<<"你的点数是:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand>=4){
				cout<<"你攻击力+1"<<endl;
				ht++;
			}else{
				cout<<"你回复20点血量"<<endl;
				hp+=20;
			}
		}
	}else if(x==14){
		cout<<"你找到了祝福祭品"<<endl;
		cout<<"似乎是用在某个祭坛的"<<endl;
		jp++;
	}else if(x==15){
		cout<<"你遇到了祝福祭坛"<<endl;
		cout<<"似乎需要献出祭品"<<endl;
		Sleep(1000);
		if(jp>0){
			jp--;
			cout<<"献祭成功!"<<endl;
			Sleep(1000);
			cout<<"1-2:血量+40,3-4:攻击力+3,5-6:获得2-3张卡"<<endl;
			Sleep(1000);
			int rand=(clock()-cl)%6+1;
			cout<<"你的点数是:";
			Sleep(1000);
			cout<<rand<<endl;
			if(rand<=2){
				hp+=40;
			}else if(rand<=4){
				ht+=3;
			}else{
				cout<<"你获得"<<rand-3<<"张卡"<<endl;
				cout<<"你获得了:";
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
			cout<<"祭品不足"<<endl;
		}
	}
}
int main(){
	int r,css=0,hitmax=65535;
	cout<<"Loading...";
	Sleep(3000);
	system("CLS");
	cout<<"骰子与卡牌"<<endl;
	Sleep(3000);
	system("CLS");
	cout<<"请选择挑战的boss:"<<endl;
	Sleep(1000);
	cout<<"1:蜘蛛人"<<endl;
	cin>>bosstype;
	cl=clock();
	while(bosstype!=1){
		cout<<"请重新选择"<<endl;
		cin>>bosstype;
	}
	Sleep(1000);
	cout<<"请选择你的攻击种类:"<<endl;
	cout<<"1:斩击   2:突刺   3:打击"<<endl;
	cin>>hittype;
	while(hittype<1 || hittype>3){
		cout<<"请重新选择"<<endl;
		cin>>hittype;
	}
	cout<<"选择成功,开始爬塔"<<endl;
	for(int tfl=1;tfl<=4;tfl++){ 
		if(tfl>=2){
			hitmax=20;
		}
		Sleep(2000);
		system("CLS");
		for(int i=1;i<=10;i++){
			css++;
			cout<<"第"<<css<<"层:"<<endl;
			money++;
			cout<<"hp:"<<hp<<" money:"<<money<<endl;
			cout<<"请选择卡牌:1,2,3"<<endl;
			cin>>r;
			while(r!=1 && r!=2 && r!=3){
				cout<<"请重新选择"<<endl;
				cin>>r;
			}
			cout<<"你选择了";
			ck[1]=(clock()-cl)%canum+1;
			ck[2]=ck[1];
			ck[3]=ck[1];
			ca(ck[1]);
			int tmp=1;
			for(int i=1;i<=3;i++){
				if(i!=r){
					tmp++;
					Sleep(1000);
					cout<<"第"<<i<<"张是:"; 
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
			cout<<"请输入任意字符继续"<<endl;
			string sr;
			cin>>sr;
			cout<<endl;
			cout<<"————————————————————————————"<<endl;
			cout<<endl; 
			if(hp<=0){
				cout<<"你失败了,得分:0"<<endl;
				return 0; 
			}
		}
		cout<<"是否打开商店"<<endl;
		cout<<"1:打开 2:不打开"<<endl; 
		cin>>r;
		while(r!=1 && r!=2){
			cout<<"请重新选择"<<endl;
			cin>>r;
		}
		if(r==1){
			money-=2; 
			cout<<"打开商店"<<endl;
			while(true){
				if(fightflag){
					cout<<"战斗前准备"<<endl;
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
					cout<<"第"<<i<<"张卡是:"<<endl;
					printcard(rand);
					flcard[i]=rand;
					if(rand==20){
						vis[20]=1; 
					} 
					Sleep(1000);
					cout<<endl; 
				}
				while(true){
					cout<<"你还有"<<money<<"点费用"<<endl;
					cout<<endl;
					if(fightflag){
						break;
					}
					cout<<"1-6:购买1-6张卡,7:刷新"<<endl;
					int r;
					cin>>r;
					while(r<1 && r>7){
						cout<<"请重新选择"<<endl;
						cin>>r;
					}
					if(r==7){
						if(money>=2 && vis[20]==0){
							cout<<"刷新成功"<<endl;
							money-=2;
							break;
						}else{
							if(vis[20]!=0){
								cout<<"费用不足,开始战斗"<<endl;
								fightflag=1;
								break;
							}else{
								cout<<"刷新故障"<<endl;
							}
						}	
					}else{
						if(money>=fy[flcard[r]]){
							money-=fy[flcard[r]];
							vis[flcard[r]]=1;
							cout<<"购买成功,你还有"<<money<<"点费用"<<endl;
							printcard(flcard[r]);
						}else{
							cout<<"费用不足"<<endl;
						}
						cout<<"1:刷新 2:开始战斗"<<endl;
						int r;
						cin>>r;
						while(r<1 && r>2){
							cout<<"请重新选择"<<endl;
							cin>>r;
						}
						if(r==1){
							if(money>=2){
								cout<<"刷新成功"<<endl;
								money-=2;
								break;
							}else{
								cout<<"刷新失败,开始战斗"<<endl;
								fightflag=1;
								break;
							}
						}else{
							cout<<"战斗前准备"<<endl;
							fightflag=1;
						}
					}
				}
				vis[20]=0;
			}
		}else{
			cout<<"战斗前准备"<<endl;
		}
		cout<<"你的卡牌有"<<endl;
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
		cout<<"基础攻击力:"<<ht<<endl;
		cout<<"基础防御力:"<<js<<endl;
		cout<<"血量:"<<hp<<endl;
		cout<<"血量上限:"<<hpmax<<endl;
		cout<<"混乱值:"<<conf<<endl;
		cout<<"混乱上限:"<<confmax<<endl;
		cout<<"暴击率:"<<bj*16.7<<"%"<<endl;
		cout<<"暴击伤害:"<<bs*100.0<<"%"<<endl;
		cout<<"眩晕率:"<<xy*16.7<<"%"<<endl;
		cout<<"吸血率:"<<xx*100<<"%"<<endl;
		cout<<"沉默率:"<<cm*16.7<<"%"<<endl;
		cout<<"基础速度:"<<speed<<endl;
		cout<<"普攻伤害:"<<pg<<endl;
		cout<<"技能伤害:"<<jn<<endl;
		cout<<"大招伤害:"<<dz<<endl;
		cout<<"输入任意字符以战斗"<<endl;
		cin>>s1;
		Sleep(1000);
		cout<<"开始战斗"<<endl;
		int rr;
		while(true){
			if(hp>hpmax){
				hp=hpmax;
			}
			hh++;
			cout<<"第"<<hh<<"回合"<<endl;
			cout<<"血量:"<<hp<<"   混乱值:"<<conf<<endl;
			cout<<"boss血量"<<boss<<endl;
			cout<<endl;
			int spfl=0;
			int mysp=0,spysp=0;
			while(mysp==spysp){
				cout<<"你的速度:";
				mysp=(clock()-cl)%6+1+speed;
				Sleep(1000);
				cout<<mysp<<endl;
				Sleep(1000);
				cout<<"他们的速度:";
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
				cout<<"boss行动"<<endl;
				cout<<endl;
				if(fxy>0){
					cout<<"boss已眩晕"<<endl;
				}else{
					fightspy();
				}
			}
			if(hp<0){
				cout<<"你失败了,得分:"<<boss<<endl;
				Sleep(5000);
				return 0;
			}
			int txd=xd;
			if(conf>confmax && confpos<0){
				confpos=2;
			}
			if(confpos>0){
				txd=0;
				cout<<"你已被混乱"<<endl;
			}
			if(confpos==0){
				conf=0;
			}
			int tflag=0;
			for(int i=1;i<=txd;i++){
				int sh=0;
				int cs=1; 
				cout<<"1:普攻 2:技能 3:大招 其他:不攻击"<<endl;
				cin>>rr;
				if(rr==1){
					if(wpg<=0){
						sh=pg;
						wpg=1; 
					}else{
						cout<<"正在冷却"<<endl;
						i--;
						cs=0;
					}
				}
				if(rr==2){
					if(wjn<=0){
						sh=jn;
						wjn=2; 
					}else{
						cout<<"正在冷却"<<endl;
						i--;
						cs=0;
					}
				}
				if(rr==3){
					if(wdz<=0){
						sh=dz;
						wdz=4;
					}else{
						cout<<"正在冷却"<<endl;
						i--;
						cs=0;
					}
				}
				if((rr==1 || rr==2 || rr==3) && cs){
					if(bj>0){
						cout<<"是否暴击:暴击";
						if(radom(bj)){
							cout<<"成功"<<endl;
							sh*=bs;
						}else{
							cout<<"失败"<<endl;
						}
					}
					if(xy>0){
						cout<<"是否眩晕:眩晕";
						if(radom(xy)){
							cout<<"成功"<<endl;
							fxy=1;
							if(spfl==1){
								fxy++;
							}
						}else{
							cout<<"失败"<<endl;
						}
					}
					if(cm>0){
						cout<<"是否沉默:沉默";
						if(radom(cm)){
							cout<<"成功"<<endl;
							fcm=1;
							if(spfl==1){
								fcm++;
							}
						}else{
							cout<<"失败"<<endl;
						}
					}
					boss-=min(sh,hitmax);
					hp+=min(sh,hitmax)*xx;
					if(sh==0){
						cout<<"未造成伤害"<<endl;
					}
					if(sh>100){
						cout<<"全力一击!"<<endl;
					}
					if(sh>1000){
						cout<<"获得了成就:全力一击!!!";
					}
				}
				cout<<"boss血量"<<boss<<endl;
				Sleep(1000);
				cout<<endl;
				if(boss<=0){
					cout<<"你赢了"<<endl;
					Sleep(3000);
					cout<<"你的卡牌有"<<endl;
					for(int i=1;i<=cardnum;i++){
						if(vis[i]){
							printcard(i);
							Sleep(1000);
							cout<<endl;
						}
					}
					cout<<"基础攻击力:"<<ht<<endl;
					cout<<"基础防御力:"<<js<<endl;
					cout<<"血量:"<<hp<<endl;
					cout<<"血量上限:"<<hpmax<<endl;
					cout<<"混乱值:"<<conf<<endl;
					cout<<"混乱上限:"<<confmax<<endl;
					cout<<"暴击率:"<<bj*16.7<<"%"<<endl;
					cout<<"暴击伤害:"<<bs*100.0<<"%"<<endl;
					cout<<"眩晕率:"<<xy*16.7<<"%"<<endl;
					cout<<"吸血率:"<<xx*100<<"%"<<endl;
					cout<<"沉默率:"<<cm*16.7<<"%"<<endl;
					cout<<"基础速度:"<<speed<<endl;
					cout<<"普攻伤害:"<<pg<<endl;
					cout<<"技能伤害:"<<jn<<endl;
					cout<<"大招伤害:"<<dz<<endl;
					cout<<"请输入任意字符继续"<<endl;
					string ss;
					cin>>ss;
					tboss+=20;
					boss=tboss;
					lspy=0;
					hp+=30; 
					cout<<"你获得一张卡牌"<<endl; 
					cout<<"你获得了:";
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
				cout<<"boss行动"<<endl;
				cout<<endl;
				if(fxy>0){
					cout<<"boss已眩晕"<<endl;
				}else{
					fightspy();
				}
			}
			if(hp<0){
				cout<<"你失败了,得分:"<<boss<<endl;
				Sleep(5000);
				string ss;
				cin>>ss;
				return 0;
			}
			cout<<"————————————————————————————"<<endl; 
		}
		bhit+=2;
	}
	cout<<"通关!"<<endl; 
	Sleep(10000); 
	return 0;
} 
