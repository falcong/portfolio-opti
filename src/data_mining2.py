#!/usr/bin/python

""" Luncher, able to lunch different stuff with different parameters.
"""

__author__ = 'pierre.ruyssen@gmail.com (Pierre Ruyssen)'

import re
import sys
import commands

from utils import debug

DEFAULT_OUTPUT = "output.csv" #output file

# list of files to execute, with the different
# combinaisons of arguments
EXECS = {"./vns |file| |rho|": 'vns',
	 "./recuit |file| |rho|": 'recuit'}

# Possible options and their list of values
OPTIONS = {'|arg1|': [1,2,4,6,8,16,56,128],
           '|arg2|': [10, 100, 1000, 10000],
           }

#If you want custom transfer from data to argument, define the function arg1()...


# number of times each combinaition is launched
NB_LUNCHS = 1

regs = ["(?P<test1>\d+\.\d+)"]

regs = map(lambda r: re.compile(r, re.MULTILINE), regs)
results_names = reduce(lambda e1, e2: e1+e2, map(lambda e: e.groupindex.keys(), regs), [])
number_of_results = len(results_names)
RESULTS = []

USAGE = "Usage: "+sys.argv[0]

#@debug.displayReturn
def mutateOptions(options):
  """ Transform the dict in list of lists of tuplets.
  """
  options2 = []
  for option in options:
    values = options[option]
    options2.append([(option, v) for v in values])
  return options2
  
@debug.displayReturn
def add_args(command, args):
  return [command+[args[i]] for i in range(len(args))]

def treat_result(executable, args, output):
  results = dict()
  for reg in regs:
    res = reg.search(output)
    if res: results.update(res.groupdict())
  assert len(results) == number_of_results, "assertion error"
  #args = dict(args)
  #args = '\t'.join(map(lambda e: str(1), args.keys()))
  args = '\t'.join(map(lambda e: str(e[1]), args))
  line = "%s\t%s\t%s\n" % (executable, args, '\t'.join([results[k] for k in results_names]))
  RESULTS.append(line)
 
def write_result():
  file = open(DEFAULT_OUTPUT, 'w')
  for line in RESULTS:
    file.write(line)
  file.close()
  
def main():
  options = mutateOptions(OPTIONS)
  arguments = [[]]
  
  for option in options:
    arguments2 = []
    for arg in arguments:
      arguments2.extend(add_args(arg, option))
    arguments = arguments2
    
  RESULTS.append("Executable\t%s\n" % ("\t".join(OPTIONS.keys()+results_names)))
  
  try:
    nb = len(arguments) * len(EXECS) * NB_LUNCHS
    cpt = 0
    for executable in EXECS:
      for arg in arguments:
        comm = executable
        for a in arg:
          comm = comm.replace(str(a[0]), str(a[1]), 1);
        for i in range(NB_LUNCHS):
          cpt += 1
          print "[%s/%s]%s" % (cpt, nb, comm)
          output = commands.getoutput(comm)
          treat_result(EXECS[executable], arg, output)
  except Exception, e:
    RESULTS.append(str(e))
    print e
  write_result()

if __name__ == "__main__":
  main()
