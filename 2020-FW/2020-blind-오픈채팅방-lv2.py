def solution(record):
    answer = []
    nicknames = {}
    for item in record:
        action = item.split()[0]
        if action != 'Leave':
            userId = item.split()[1]
            nickname = item.split()[2]
            nicknames[userId] = nickname
    
    for item in record:
        print(item)
        action = item.split()[0]
        result = nicknames[item.split()[1]]
        if (action == 'Enter'):
            result += '님이 들어왔습니다.'
            answer.append(result)
        elif (action == 'Leave'):
            result += '님이 나갔습니다.'
            answer.append(result)
        else:
            continue
    
    return answer

solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])