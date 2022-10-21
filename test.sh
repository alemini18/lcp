

for j in `ls dataset`
do
    echo $j
    echo `./eps/lz77 <dataset/$j` >> $j
    for i in `cat epsilons`
    do
        echo $i
        ./lz76 $i < dataset/$j  >> $j
        echo $i >> $j
    done
done
