if [[ ! -d $1 ]]
then
    echo "First argument must be a directory"
    exit 2
fi

for j in `ls $1`
do
    echo $j
    echo `./eps/lz77 < $1/$j` >> ans/$j
    for i in `cat epsilons`
    do
        echo $i
        ./lz76 $i < $1/$j  >> ans/$j
        echo $i >> ans/$j
    done
done
