#! /bin/bash
[ "$(echo $1 | cut -f2 -d.)" == "cpp" ] && g++ "$1" -o 'run.out' && chmod +x 'run.out'

function run_code(){
  for i in inputs/*.txt;
    do
      output_file=$(basename "$i").output
      "$1" < "$i" > outputs/"$output_file"
  done;
  echo "Done"
}

if [ -f "run.out" ]
  then
    run_code "./run.out"
  elif [ -f "driver.py" ]
    then run_code "python3 driver.py"
fi
