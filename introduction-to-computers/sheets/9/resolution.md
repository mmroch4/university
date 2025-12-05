# sa

```bash
cd ~ # Both navigates to home directory
cd
```

```bash
mkdir -p dir1/dir2/dir4/dir6 dir1/dir3 dir1/dir2/dir5 # Create empty directories
```

```bash
cd dir1/dir2/dir4/dir6/../.. # It goes to dir1/dir2
```

```bash
touch f1.txt h22.txt g368.pdf ./dir4/g22.doc ../dir3/f3a.txt ../dir3/g56.doc ../dir3/g3x.pdf # Create blank files
```

```bash
find dir1/dir2 -name "[fg][35][4-7a-z].txt" -print # Outputs every file inside dir2 that matches the regular expression
find dir1/dir3 -name "[fg][35][4-7a-z].txt" -print # Outputs every file inside dir3 that matches the regular expression
```

```bash
rm -rf dir1/dir2 # Forcefully and recursively deletes dir2
```

```bash
mv g56.doc j52.sh # Renames file g56.doc to j52.sh
mv g3x.pdf g3x.out # Renames file g3x.pdf to g3x.out
```

```bash
chmod 644 f3a.txt # Changes f3a.txt permissions to rw-r--r-- 
chmod 755 g3x.out # Changes g3x.out permissions to rwxr-xr-x
chmod 754 j52.sh # Changes j52.sh permissions to rwxr-xr--
```

```bash
cat q1.txt | sed ’s/Ring/Sword/g’ > q2.txt # Replace every ´Ring´ with ´Sword´, writing it on q2.txt
cat q2.txt | grep -v Mordor # Outputs every line that DOES NOT contain the word ´Mordor´ in q2.txt
wc -l q2.txt # Outputs the number of lines of the file q2.txt
```

```bash
sed ’s/half/two\ thirds/g’ < f1.txt > f2.txt # Replace every ´half´ with ´two thirds´, writing it on f2.txt 
diff f1.txt f2.txt # Outputs the difference between f1.txt and f2.txt
sed ’s/like/do\ not\ like/g’ < f1.txt > f2.txt # Replace every ´like´ with ´do not like´, writing it on f2.txt
diff f1.txt f2.txt # Outputs the difference between f1.txt and f2.txt
```

```bash
sort -n < numbers1.txt > numbers2.txt # Numerically sorts numbers1.txt content and write it in number2.txt
sort -d < words1.txt > words2.txt # Alphabetically sorts words1.txt content and write it in words2.txt
```

```bash
ps -A | wc -l # Outputs the number of active processes 
```

```bash
kill -9 3577 3578 3579 # Kill processes 3577, 3578 and 3579
```
