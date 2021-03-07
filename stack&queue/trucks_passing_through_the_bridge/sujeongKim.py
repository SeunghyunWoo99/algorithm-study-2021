def solution(bridge_length, max_weight, truck_weights):
    time = 0
    bridge = [0] * bridge_length
    
    while True:
        if len(truck_weights) <= 0 and sum(bridge) == 0:
            return time
        bridge.pop(0)
        if truck_weights and sum(bridge) + truck_weights[0] <= max_weight:
            bridge.append(truck_weights.pop(0))
        else:
            bridge.append(0)
        time += 1
    
    return time
