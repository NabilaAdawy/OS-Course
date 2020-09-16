for i in $(seq 10)
do
  Nab=$( tail -n 1 ex2a.txt)
  echo "$(($Nab+1))">>ex2a.txt
done
