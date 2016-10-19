@ECHO ON

mkdir facts
mkdir reports

for /r %%f in ( ..\factRuEval-2016\devset\*.txt ) do (
  ..\tomitaparser.exe config_win.proto < %%f
  move facts\facts.proto facts\%%~nf.proto
)

for /r %%f in ( .\facts\*.proto ) do C:\Python27\python convert\parsefacts.py %%f > facts\%%~nf.task1

C:\Python34\python ..\factRuEval-2016\scripts\t1_eval.py -s ..\factRuEval-2016\devset\ -t facts\ -o reports\ -l
