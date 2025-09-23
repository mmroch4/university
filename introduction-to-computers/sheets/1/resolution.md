# Resolution

1. ```bash
    pwd
   ```

2. ```bash
   mkdir aulas/ic/praticas/teste aulas/ic/arquivo -p
   ```

3. ```bash
   cd ~ && tree
   ```

4. ```bash
   cd aulas/ic/praticas/teste
   cat > url.txt
   ```

5. ```bash
   cp -a url.txt ../
   ```

6. ```bash
    rm url.txt
    cd ..
    cp -a url.txt ./teste
   ```

7. ```bash
    rm url.txt
    cp -a -r -v teste/ ../arquivo/
   ```

8. ```bash
    rm -r teste
    cp -a -v -r ../arquivo/teste/ .
   ```

9. ```bash
    touch numeros.txt

    nano script.sh
    # for i in $(seq 100 1000);
    # do
    #        echo $i
    # done

    bash script.sh | cat > numeros.txt

    cat numeros.txt
    head -n 20 numeros.txt
    tail -n 20 numeros.txt
   ```

10. ```bash
    cat ./teste/url.txt | cat > url2.txt
    diff url2.txt ./teste/url.txt  -y
    rm url2.txt
    ```

11. ```bash
    cd teste
    ls -l
    chmod a-rwx url.txt && chmod a+rw url.txt
    chmod a-rwx url.txt && chmod u+rw url.txt && chmod g+rw url.txt
    chmod a-rwx url.txt && chmod u+rw url.txt
    chmod a-rwx url.txt && chmod a+rx url.txt && chmod u+w url.txt
    chmod a-rwx url.txt && chmod a+rw url.txt && chmod o-w url.txt
    ```

12. ```bash
    ...
    ```

13. ```bash
    cd ..
    mv numeros.txt ./teste/
    tar czf teste.tar.gz teste/
    mv teste.tar.gz ../arquivo/
    rm -r teste/
    tar -xf ../arquivo/teste.tar.gz
    ```
