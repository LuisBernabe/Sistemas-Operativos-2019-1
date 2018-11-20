
#!/usr/bin/env bash





#cat /dev/stdin
file="numeros.txt"

lst=()


echo "======================="
while  IFS= read -r line
do
  #echo $line
  lst+=(${line})

done <"$file"



for item in ${lst[*]}
do
  printf "%d\n" $item

done
echo "======================="
#================Algoritmo======================
n=${#lst[*]}
gap=$((n/2))
#l=$gap
#j=7
#echo "j: ${j}"
echo "lst(0): ${lst[0]}"
#valT=[$j -gt ${gap}]
#echo "valT ${valT}"
#${lst[$((j-gap))]} -gt $temp
#===================================================

#temp=${lst[$j-$j]}
#echo "temp: ${temp}"
#i=0
#while [ ${lst[$((j-gap))]} -ge $temp  -a $j -ge ${gap} -a ${i} -le 10 ];
#do
#  echo "i: ${i}"
#  i=$((i+1))
#done

#gap=$((gap/7))
#echo "gap+1 ${gap}"
#====================================================

while [ $gap -gt 0 ];
do
    i=$gap
    while [ ${i} -lt ${n} ];
    do
      temp=${lst[$i]}
      j=$i #
      while  [ ${lst[$((j-gap))]} -gt $temp  -a $j -ge ${gap} ];
      do
        echo "j: ${j}"
        lst[$j]=${lst[$((j-gap))]}
        j=$((j-gap)) #
      done
      #echo "temp: ${temp}"
      #gap=$((gap/2))
      #echo "gap1: ${gap}"
      lst[$j]=$temp

    done
    gap=$((gap/2))
    i=$((i+1))
done
