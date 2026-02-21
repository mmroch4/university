t=[(["_"]*29).copy() for _ in range(28)]
s=[2,5,7]
a=[21,13,7,0]
u=0
while u<3:
  c=0
  while s[u]+c<14:
    y=a[u]-c
    x=s[u]+c
    p=t[y]
    p[x]="o"
    p[26-x]="o"
    if y>a[u+1]:
      p[x-1]="*"
      p[26-x+1]="*"
    c+=1
  u+=1
t[27][13],t[13][8],t[13][18],t[7][9],t[7][17],t[0][13],t[1][13],t[8][5],t[8][21]=["o"]*5+["*"]*4
u=27
while 20 < u:
  t[u][12], t[u][14] = ["o"]*2
  u-=1
k=4
while k < 12:
  t[21][k],t[21][26-k]=["o"]*2
  k+=2
print("\n".join(map(lambda x:"".join(x),t)))