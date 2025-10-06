# Resolution

1. ```bash
   nano & # Runs nano as a background process
   ps # Lists the active processes
   jobs # Lists the active jobs
   kill %1 # Stop the process %1
   ```

2. ```bash
   tar -xvzf figures.tgz

   ls [0-9]*
   ls [^f]*
   ls ????.*
   ls *[^g].*
   ls *.png *.jpg
   ls *.tiff
   ls | grep tiff
   ```

3. ```bash
   ps | cat > proc.txt
   ls | sort
   # (C) MISSING
   cat > numeros.txt
   cat numeros.txt | sort
   ```

4. ```bash
   mv ~/Downloads/users.txt ~/Desktop
   head -10 users.txt
   tail -10 users.txt
   cat users.txt | grep "^[^c]"
   cut -f 5 -d ":" users.txt | sort | cat > alunos2004.txt
   cat alunos2004.txt | grep "[aA]$"
   cut -f 1 -d " " alunos2004.txt
   cut -f 1 -d " " alunos2004.txt | awk '{print tolower($1)}' | uniq | wc -w
   ```

5. ```bash
   cat users.txt | grep "/home/\S" | cut -f 5 -d ":" | sort
   ```

6. ```bash
   cat users.txt | grep "/home/\S" | wc -l
   ```

7. ```bash
   sed 's/:/|/g' users.txt | cat > users2.txt
   ```

8. ```bash
   tar -cf users.tgz users.txt
   file users.txt
   file users.tgz
   ```

9. ```bash
   ps -U root -u root
   ```

10. ```bash
   find -size +1M
   ```


11. ```bash
   cat lines.txt | grep -E '^[a-zA-Z]+[0-9]+$'
   ```
