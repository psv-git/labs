# PUBLIC FUNCTIONS ============================================================

def read_file(file):
    wheels_dict = {} # {active_wheel_id: [passive_wheel_id, ...], ...}
    shape = [0, 0]
    for index, line in enumerate(file):
        if index == 0:
            shape = [int(ss) for ss in line.split() if ss.isdigit()]
        else:
            pair = [int(ss) for ss in line.split() if ss.isdigit()]

            passive_wheels_list = wheels_dict.get(pair[0], [])
            passive_wheels_list.append(pair[1])
            wheels_dict[pair[0]] = passive_wheels_list

            passive_wheels_list = wheels_dict.get(pair[1], [])
            passive_wheels_list.append(pair[0])
            wheels_dict[pair[1]] = passive_wheels_list

    return shape, wheels_dict

# =============================================================================

def generate_test(out_file_path, wheels_count, pairs_count):
    import random
    out_file = open(out_file_path, "w")
    out_file.write("{0} {1}\n".format(wheels_count, pairs_count))
    wheel_counter = 1
    tmp = []
    for i in range(0, pairs_count):
        tmp.append([wheel_counter, wheel_counter + 1])
        if wheel_counter % pairs_count == 0:
            random.shuffle(tmp)
            for item in tmp:
                out_file.write("{0} {1}\n".format(item[0], item[1]))
            tmp.clear()
        wheel_counter += 1
    out_file.close()
