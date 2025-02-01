{$CLEO .cs}

// Variáveis
0001: wait 1000 ms

// Função de ativação do cheat
:start
// Ativar cheat e tornar o usuário imortal
if 00E1:   player $PLAYER_CHAR defined // Se o jogador está presente
then
    0A89: kill_actor $PLAYER_ACTOR // Garantir que o jogador seja morto inicialmente
end

// Imortalidade para quem ativar o cheat
:imortalidade
if 00E1:   player $PLAYER_CHAR defined
then
    01B2: set_actor $PLAYER_ACTOR invulnerable 1 // Jogador se torna imortal
end

// Criar caos extremo
:create_chaos
for 0 to 100
    0A2E: create_explosion_at_random_position radius 100.0 type 3 // Explosões
    0A59: create_car #SULTAN at_random_position // Criar carros aleatórios
    0A59: create_car #SAVANNA at_random_position
    0A59: create_car #BANSHEE at_random_position
    0A59: create_car #MESA at_random_position
    0A88: create_pedestrian #PED_DRUNK at_random_position // Criar pedestres bêbados
    0A88: create_pedestrian #PED_GANG at_random_position // Criar pedestres de gangue
    0A2E: create_weapon 24 at_random_position // Espalhar armas aleatórias
    wait 500 ms
end

// Gerar terremotos e furacões para criar lag no servidor
:create_lag
for 0 to 20
    0A2E: create_explosion_at_random_position radius 50.0 type 2 // Terremoto
    0A2E: create_explosion_at_random_position radius 50.0 type 4 // Furacão
    wait 100 ms
end

// Gerar caos total no mapa
:total_chaos
for 0 to 100
    0A2E: create_explosion_at_random_position radius 100.0 type 3 // Explosões massivas
    0A59: create_car #SULTAN at_random_position
    0A59: create_car #SAVANNA at_random_position
    0A59: create_car #BANSHEE at_random_position
    0A59: create_car #MESA at_random_position
    0A88: create_pedestrian #PED_DRUNK at_random_position
    0A88: create_pedestrian #PED_GANG at_random_position
    0A2E: create_weapon 24 at_random_position
    wait 100 ms
end

// Criar pequenos lag spikes para testar o sistema
:create_lag_spikes
for 0 to 50
    00D6: create_object 29 at_random_position // Criar objetos para forçar o servidor a calcular
    00D6: create_object 56 at_random_position
    wait 50 ms
end

// Forçar uma grande quantidade de veículos para se mover em alta velocidade
:move_vehicles_random
for 0 to 30
    0A59: create_car #SULTAN at_random_position
    0A59: create_car #SAVANNA at_random_position
    0A2E: set_car_velocity #SULTAN to 300.0 300.0 0.0 // Super velocidade
    0A2E: set_car_velocity #SAVANNA to 350.0 350.0 0.0 // Super velocidade
    wait 300 ms
end

// Simular caos com mais pedestres e mais armas
:create_more_chaos
for 0 to 50
    0A88: create_pedestrian #PED_WALKER at_random_position
    0A88: create_pedestrian #PED_GANG at_random_position
    0A2E: create_weapon 29 at_random_position // Faca
    0A2E: create_weapon 30 at_random_position // Rifle
    0A2E: create_weapon 32 at_random_position // Munição
    wait 200 ms
end

// Voltar ao início para repetir o caos
jump @start