def solution(records):
    answer = []

    nickname_log = {}
    access_log = []

    for record in records:
        words = record.split()
        
        if words[0] == "Enter":
            nickname_log[words[1]] = words[2]
            access_log.append([words[0], words[1]])
        elif words[0] == "Leave":
            access_log.append([words[0], words[1]])
        elif words[0] == "Change":
            nickname_log[words[1]] = words[2]

    for record in access_log:
        log = nickname_log[record[1]]
        
        if record[0] == "Enter":
            log+="님이 들어왔습니다."
        elif record[0] == "Leave":
            log+="님이 나갔습니다."
        
        answer.append(log)
        
    return answer