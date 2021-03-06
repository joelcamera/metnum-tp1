import csv
from StringIO import StringIO

input_path = '../../data/mlb_2016_games.csv'
output_path = '../../data/mlb_2016_games.dat'
output_info_path = '../../data/mlb_2016_teams.txt'

with open(input_path,'rb') as csvfile,\
     open(output_info_path,'w') as infofile,\
     open(output_path,'w') as outfile:
    score_reader = csv.reader(csvfile,delimiter=',',skipinitialspace=True)

    teams = {}
    n_games = 0
    team_id = 0
    # String with info of the games.
    out_str = StringIO()
    for row in score_reader:
        d, t1, t2, s1, s2 = row[0], row[3], row[6], row[9], row[10]

        if t1 in teams:
            t1_id = teams[t1]
        else:
            t1_id = team_id
            teams[t1] = t1_id
            team_id += 1

        if t2 in teams:
            t2_id = teams[t2]
        else:
            t2_id = team_id
            teams[t2] = t2_id
            team_id += 1

        n_games += 1
        out_str.write(' '.join(map(str, [d, t1_id, s1, t2_id, s2])) + '\n')

    # Write number of teams and games
    outfile.write(str(len(teams)) + ' ' + str(n_games) + '\n')
    # Write games details
    outfile.write(out_str.getvalue())

    for k, v in sorted(teams.iteritems(), key=lambda x: x[1]):
        infofile.write('{}: {}\n'.format(v, k))
