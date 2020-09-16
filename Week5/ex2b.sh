
for i in $(seq 10)
do
  lockfile -r 0 ex2b.lock || exit 1
  Nab=$( tail -n 1 ex2b.txt)  
  echo "$(($Nab+1))">> ex2b.txt
  rm -f ex2b.lock
done
