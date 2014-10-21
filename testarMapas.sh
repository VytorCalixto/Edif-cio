#!/bin/bash
#@authors ibsa14 enba14 vsbc14

echo "Extraindo arquivos:"
wget -qO- http://www.inf.ufpr.br/luciano/grad/ci067_2014_2/site.tar.gz | tar -xzv
wget -qO- http://www.inf.ufpr.br/luciano/grad/ci067_2014_2/avaliacao.tar.gz | tar -xzv
make
clear

numfiles=$(($(ls -l avaliacao/ | grep '^-' | wc -l) + $(ls -l site/ | grep '^-' | wc -l)))
echo "Executando $(($numfiles/2)) testes."
FILES=avaliacao/*.out
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
rm -fr avaliacao

