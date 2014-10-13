#!/bin/bash
#@authors ibsa14 enba14 vsbc14


wget http://www.inf.ufpr.br/luciano/grad/ci067_2014_2/site.tar.gz
tar -xzf site.tar.gz
rm site.tar.gz
make
clear

FILES=site/*.out
for f in $FILES
do
	name=${f%\.*}
	output=$(time ./fogo < $(echo "$name.in"))
	result=$(echo "$output" | tail -1)
	expected=$(cat $(echo "$name.out"))
	if [ "$result" != "$expected" ]; then
		echo -e "\e[0;31mErro no teste $name.\e[0m"
	else
		echo -e "\e[0;32mTeste $name ok!\e[0m"
	fi
	echo -e "Esperado: $expected. Retornado: $result."
done

rm -fr site

