#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
void main()
{
char label[10],opcode[10],operand[10],code[10],ab[20],addr[20],symbol[10],locctr[20],value[20]; 
int i,len=20,slen,start;
FILE *f1,*f2,*f3,*f4,*f5; 
f1=fopen("intermediate.txt","r");
f2=fopen("SYMTAB.txt","r");
f3=fopen("objcode.txt","w");
f4=fopen("file.txt","w");
f5=fopen("OPTAB1.txt","r"); 
fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
fprintf(f4,"%s\t %s\t %s\n",label,opcode,operand); 
fprintf(f3,"H^%s^00%s^00%d",label,operand,len);
fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
fprintf(f3,"\nT^00%d^%d",atoi(locctr),len);
}
while(strcmp(opcode,"END")!=0)
 

{
if(strcmp(opcode,"BYTE")==0)
{
if(operand[0]=='C')
{
slen=strlen(operand)-3;
fprintf(f4,"%d\t%s\t%s\t%s\t",atoi(locctr),label,opcode,operand);
fprintf(f3,"^");
for(i=2;i<(slen+2);i++)
{
sprintf(ab,"%x",operand[i]);
fprintf(f4,"%s",ab);
fprintf(f3,"%s",ab);
}
fprintf(f4,"\n");
}
else if(operand[0]=='X')
{
slen=strlen(operand)-3; 
fprintf(f4,"%d\t%s\t%s\t%s",atoi(locctr),label,opcode,operand); 
fprintf(f3,"^");
for(i=2;i<(slen+2);i++)
{
fprintf(f4,"\t%c",operand[i]);
fprintf(f3,"%c",operand[i]);
}
fprintf(f4,"\n");
}
}
else if(strcmp(opcode,"WORD")==0)
{
 

fprintf(f4,"%d\t%s\t%s\t%s\t0000%s\n",atoi(locctr),label,opcode,operand,operand); 
fprintf(f3,"^0000%s",operand);
}
else if(((strcmp(opcode,"RESW")==0)||(strcmp(opcode,"RESB")==0)))
{
fprintf(f4,"%d\t%s\t%s\t%s\n",atoi(locctr),label,opcode,operand);
}
else
{
fscanf(f5,"%s%s",code,value); 
while(strcmp(code,"END")!=0)
{
if(strcmp(opcode,code)==0) 
break;
fscanf(f5,"%s%s",code,value);
}
fscanf(f2,"%s%s",symbol,addr); 
while(!feof(f2))
{
if(strcmp(
symbol,operand)==0) break; 
fscanf(f2,"%s%s",symbol,addr);
}
fprintf(f4,"%d\t%s\t%s\t%s\t%d%d\n",atoi(locctr),label,opcode,operand,atoi(value),atoi(addr)); 
fprintf(f3,"^%d%d",atoi(value),atoi(addr));
}
rewind(f2); 
rewind(f5);
fscanf(f1,"%s%s%s%s",locctr,label,opcode,operand);
}
fprintf(f3,"\n");
 

if(strcmp(opcode,"END")==0)
{
fprintf(f3,"E^00%d",start); 
fprintf(f4,"%d\t%s\t%s\t%s\n",atoi(locctr),label,opcode,operand);
}
}
