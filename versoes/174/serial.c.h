void Serial_Hit (u32 kmh, bool is_back) {
    Serial.print(F("> "));
    Serial.print(kmh);
    if (is_back) {
        Serial.print(F(" !"));
    }
    Serial.println();
}
 
void Serial_Score (void) {
    u32 ps[2] = {0,0};
    u32 bests[2][2] = { {0,0}, {0,0} };
    u32 p0 = ps[0] + bests[0][0] + bests[0][1];
    u32 p1 = ps[1] + bests[1][0] + bests[1][1];
    u32 avg = (p0 + p1) / 2;
    u32 total = (S.equilibrio ? min(avg, min(p0,p1)*11/10) : avg);
    u32 bruta = ((G.ps[0]/100)+(G.ps[1]/100))/2;
    u32 equ1 = min(((G.ps[0]/100)),((G.ps[1]/100)))*11/10;
    u32 equ2 = min(bruta, equ1);
    u32 equ3 = bruta - equ2;
    
    Serial.println();
    Serial.println(F("-------------------------------------------------"));
    sprintf_P(STR, PSTR("        %10s"), S.names[0]);
    Serial.print(STR);
    Serial.print(F(" / "));
    sprintf_P(STR, PSTR("%s"), S.names[1]);
    Serial.print(STR);
    Serial.println();
    Serial.println(F("-------------------------------------------------"));
    
    //OK – TEMPO DE JOGO
    sprintf_P(STR, PSTR("%10S: "), F("Tempo de Jogo........"));
    Serial.print(STR);
    Serial.print(G.time/1000);
    Serial.println(F(" s"));
    
    //OK – TEMPO RESTANTE
    sprintf_P(STR, PSTR("%10S: "), F("Tempo Restante......."));
    Serial.print(STR);
    Serial.print(G.time > S.timeout ? 0 : (S.timeout-G.time)/1000);
    Serial.println(F(" s"));
    
    //OK – QUANTIDADE BOLAS
    sprintf_P(STR, PSTR("%10S: "), F("Quantidade Bolas....."));
    Serial.print(STR);
    Serial.println(Falls());
    
    //OK – QUANTIDADE DE GOLPES
    sprintf_P(STR, PSTR("%10S: "), F("Golpes..............."));
    Serial.print(STR);
    Serial.println(G.hits);

    //OK – JUIZ
    sprintf_P(STR, PSTR("%10S: "), F("Juiz................."));
    Serial.print(STR);
    Serial.println(S.juiz);

    //OK - PONTUAÇÃO BRUTA 
    Serial.println(F("-------------------------------------------------"));
    sprintf_P(STR, PSTR("Pontuação Bruta......:%5ld"), ((G.ps[0]/100)+(G.ps[1]/100))/2);
    Serial.print(STR);
    Serial.println(F(" pts"));

    //OK – EQUILÍBRIO (PTS PERDIDOS)
    sprintf_P(STR, PSTR("Equilibrio...........: "));
    Serial.print(STR);
    Serial.print(equ3);
    Serial.println(F(" pts (-)"));
             
    //OK – QUEDAS (PTS PERDIDOS)
    sprintf_P(STR, PSTR("Quedas...............: "));
    Serial.print(STR);
    Serial.print((((bruta - equ3)*(3*Falls())/100)));
    Serial.println(F(" pts (-)"));
        
    //OK - VELOCIDADE MÉDIA
    sprintf_P(STR, PSTR("Velocidade Média.....: "));
    Serial.print(STR);
    if (G.time > 5000) {
        Serial.print((int)G.pace[0]);
        Serial.println(F(" Km/h"));
    } else {
        Serial.println("---");
    }
    
    //OK – PONTUAÇÃO FINAL
    sprintf_P(STR, PSTR("%10S: "), F("PONTUAÇÃO FINAL......"));
    Serial.print(STR);
    Serial.print(G.total);
    Serial.println(F(" pts"));
    
    //OK - PLACAR INDIVIDUAL
    Serial.println(F("-------------------------------------------------"));
    sprintf_P(STR, PSTR("%10S: "), F("Jogador à esquerda..."));
    Serial.print(STR);
    Serial.println(S.names[0]);
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação............"));
    Serial.print(STR);
    Serial.print(G.ps[0]/100);
    Serial.println(F(" pts"));
        //Não mostra se não estiver marcando destrezas
        if (!S.potencia == 0) {
        //jogador 0
        //inicio dos valores
            int sum0 = 0;
            Serial.print(F("Golpes ESQ [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum0 += G.bests[0][0][k];
                sprintf_P(STR, PSTR("%3d "), (int)G.bests[0][0][k]);
                Serial.print(STR);
            }
            Serial.print(F("] => "));
            Serial.print(sum0/HITS_BESTS);
        Serial.println();
        
            int sum1 = 0;
            Serial.print(F("Golpes DIR [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum1 += G.bests[0][1][k];
                sprintf_P(STR, PSTR("%3d "), (int)G.bests[0][1][k]);
                Serial.print(STR);
            }
            Serial.print(F("] => "));
            Serial.println(sum1/HITS_BESTS);
        //fim valores segunda linha
     //fim jogador 0
     
        } else {
    }
    //fim condição para marcar destrezas
     
    Serial.println(F("-------------------------------------------------"));
    sprintf_P(STR, PSTR("%10S: "), F("Jogador à direita...."));
    Serial.print(STR);
    Serial.println(S.names[1]);
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação............"));
    Serial.print(STR);
    Serial.print(G.ps[1]/100);
    Serial.println(F(" pts"));
            //Não mostra se não estiver marcando destrezas
        if (!S.potencia == 0) {
        //jogador 1
        //inicio dos valores
            int sum2 = 0;
            Serial.print(F("Golpes ESQ [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum2 += G.bests[1][0][k];
                sprintf_P(STR, PSTR("%3d "), (int)G.bests[1][0][k]);
                Serial.print(STR);
            }
            Serial.print(F("] => "));
            Serial.print(sum2/HITS_BESTS);
        Serial.println();
        
            int sum3 = 0;
            Serial.print(F("Golpes DIR [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum3 += G.bests[1][1][k];
                sprintf_P(STR, PSTR("%3d "), (int)G.bests[1][1][k]);
                Serial.print(STR);
            }
            Serial.print(F("] => "));
            Serial.println(sum3/HITS_BESTS);
        //fim valores segunda linha
    //fim jogador 1  
        } else {
    }
    //fim condição para marcar destrezas
    Serial.println(F("-------------------------------------------------"));
    //destrezas
    //fim

    //sprintf_P(STR, PSTR("(v%d.%d / %dcm / %ds / pot=%d / equ=%d / cont=%d / max=%d)"),
     sprintf_P(STR, PSTR("(CFG:%dcm/%ds/pot=%d/equ=%d/cont=%d/fim=%d/max=%d)"),
                S.distancia,
                (int)(S.timeout/1000),
                (int)S.potencia,
                (int)S.equilibrio,
                (int)CONT_PCT,
                (int)ABORT_FALLS,
                (int)S.maxima,
                (int)S.sensibilidade);
    Serial.println(STR);
    Serial.println(F(" "));
}
 
void Serial_Log (void) {
    int ball  = 0;
    u32 ps[2] = {0,0};
    for (int i=0 ; i<S.hit ; i++) {
        s8  dt  = S.dts[i];
        u8  kmh = G.kmhs[i];
 
        if (dt == HIT_SERV) {
            ball = ball + 1;
            Serial.print(F("-- Sequencia "));
            sprintf_P(STR, PSTR("%2d"), ball);
            Serial.print(STR);
            Serial.println(F(" ----------------"));
        }
 
        if (dt == HIT_NONE) {
            continue;
        }
 
        Serial.print(F("  "));
        if (i%2 == 0) {
            if (dt < 0) {
                Serial.print(F("! "));
            } else {
                Serial.print(F("  "));
            }
        } else {
            Serial.print(F("          "));
        }
 
        int back2 = (i%2==1 and dt<0);
 
        if (dt == HIT_SERV) {
            Serial.print(F("****"));
        } else {
            sprintf_P(STR, PSTR("%4d"), (dt>0?dt:-dt)*10);
            Serial.print(STR);
            if (back2) {
                Serial.print(F(" !"));
            }
        }
 
        if (i==S.hit-1 || S.dts[i+1]==HIT_NONE || S.dts[i+1]==HIT_SERV) {
            Serial.println();
            Serial.println(F("   -----   -----"));
            sprintf_P(STR, PSTR("   %5ld   %5ld"), ps[0]/100, ps[1]/100);
            Serial.println(STR);
        } else if (dt == HIT_SERV) {
            // ignore
        } else {
            u16 pt = ((u16)kmh)*((u16)kmh);
            ps[1 - i%2] += pt;
 
            Serial.print(F("  "));
            if (!back2) {
                Serial.print(F("  "));
            }
            if (i%2 == 0) {
                Serial.print(F("        "));
            }
            sprintf_P(STR, PSTR("(%3d / %4d)"), kmh, pt);
            Serial.print(STR);
        }
        Serial.println();
        delay(50);
    }
    //Serial.println();
 
    if (S.potencia) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                int sum = 0;
                for (int k=0; k<HITS_BESTS; k++) {
                    s8 v = G.bests[i][j][k];
                    if (!S.potencia) {
                        v = POT_VEL;
                    }
                    sum += v;
                }
                int avg = sum / HITS_BESTS;
                bests[i][j] = avg*avg * POT_BONUS * HITS_BESTS;
            }
        }
}
 
    u32 p0 = ps[0] + bests[0][0] + bests[0][1];
    u32 p1 = ps[1] + bests[1][0] + bests[1][1];
 
    Serial.println(F("-------------------------------------------------"));
    Serial.println();
    Serial.println(F("    Atleta    Vol     Esq     Dir   Total"));
    sprintf_P(STR, PSTR("%10s: %5ld + %5ld + %5ld = %5ld pts"),
        S.names[0], ps[0]/100, bests[0][0]/100, bests[0][1]/100, p0/100);
    Serial.println(STR);
    sprintf_P(STR, PSTR("%10s: %5ld + %5ld + %5ld = %5ld pts"),
        S.names[1], ps[1]/100, bests[1][0]/100, bests[1][1]/100, p1/100);
    Serial.println(STR);
    Serial.println();
 
    u32 avg   = (p0 + p1) / 2;
    u32 total = (S.equilibrio ? min(avg, min(p0,p1)*11/10) : avg);
/*
    sprintf_P(STR, PSTR("MED: %ld | MIN+10%%: %ld | MIN: %ld"),
                    (p0 + p1) / 2 / 100,
                     min(p0,p1)*11 / 1000,
                     total / 100);
    Serial.println(STR);
*/
    Serial.println(F("-----------------------------------------------"));
    u32 pct = min(990, Falls()*CONT_PCT);
    //sprintf_P(STR, PSTR(">>> %ld x %d%% = %ld"), total/100, pct, total*pct/10000);
    sprintf_P(STR, PSTR("Pontuação Bruta..: %5ld pts"), avg/100);
    Serial.println(STR);
    sprintf_P(STR, PSTR("Equilibrio.......:  %2ld pts (-)"), (S.equilibrio ? (avg/100)-(total/100) : 0));
    Serial.println(STR);
    sprintf_P(STR, PSTR("Quedas...........:  %2ld pts (-)"), total*pct/100000);
    Serial.println(STR);
    sprintf_P(STR, PSTR("Golpes...........:  "));
    Serial.print(STR);
    Serial.println(G.hits);
    sprintf_P(STR, PSTR("Pontuação Final..: %5ld pts"), total*(1000-pct)/100000);
    Serial.println(STR);
    Serial.println(F("-------------------------------------------------"));
}
 
int Serial_Check (void) {
    static char CMD[32];
    static int  i = 0;
 
    char c;
    while (Serial.available()) {
        c = Serial.read();
        if (c=='\n' || c=='\r' || c=='$' ) {
            if (i == 0) {
                                // skip
            } else {
                CMD[i] = '\0';
                goto _COMPLETE;   // complete
            }
        } else {
            CMD[i++] = c;       // continue
        }
    }
    return IN_NONE;
_COMPLETE:
    i = 0;
 
    if (strncmp_P(CMD, PSTR("restaurar"), 9) == 0) {
        return IN_RESET;
    } else if (strncmp_P(CMD, PSTR("reiniciar"), 9) == 0) {
        return IN_RESTART;
    } else if (strncmp_P(CMD, PSTR("terminar"), 8) == 0) {
        return IN_TIMEOUT;
    } else if (strncmp_P(CMD, PSTR("desfazer"), 8) == 0) {
        return IN_UNDO;
    } else if (strncmp_P(CMD, PSTR("placar"), 6) == 0) {
        Serial_Score();
        return IN_NONE;
    } else if (strncmp_P(CMD, PSTR("relatorio"), 9) == 0) {
        Serial_Score();
        Serial_Log();
        return IN_NONE;
    } else if (strncmp_P(CMD, PSTR("tempo "), 6) == 0) {
        S.timeout = ((u32)atoi(&CMD[6])) * 1000;
    } else if (strncmp_P(CMD, PSTR("distancia "), 5) == 0) {
        S.distancia = atoi(&CMD[10]);
    } else if (strncmp_P(CMD, PSTR("velocidades sim"), 15) == 0) {
        S.velocidades = 1;
    } else if (strncmp_P(CMD, PSTR("velocidades nao"), 15) == 0) {
        S.velocidades = 0;
    } else if (strncmp_P(CMD, PSTR("potencia sim"), 12) == 0) {
        S.potencia = 1;
    } else if (strncmp_P(CMD, PSTR("potencia nao"), 12) == 0) {
        S.potencia = 0;
    } else if (strncmp_P(CMD, PSTR("equilibrio sim"), 14) == 0) {
        S.equilibrio = 1;
    } else if (strncmp_P(CMD, PSTR("equilibrio nao"), 14) == 0) {
        S.equilibrio = 0;
    } else if (strncmp_P(CMD, PSTR("maxima "), 7) == 0) {
        S.maxima = atoi(&CMD[7]);
    } else if (strncmp_P(CMD, PSTR("sensibilidade "), 13) == 0) {
        S.sensibilidade = atoi(&CMD[13]);        
/*
    } else if (strncmp_P(CMD, PSTR("continuidade "), 13) == 0) {
        S.continuidade = atoi(&CMD[13]);
*/
    } else if (strncmp_P(CMD, PSTR("esquerda "), 9) == 0) {
        if (strlen(&CMD[9]) < 15) {
            strcpy(S.names[0], &CMD[9]);
        } else {
            goto ERR;
        }
    } else if (strncmp_P(CMD, PSTR("direita "), 8) == 0) {
        if (strlen(&CMD[8]) < 15) {
            strcpy(S.names[1], &CMD[8]);
        } else {
            goto ERR;
        }
    } else if (strncmp_P(CMD, PSTR("juiz "), 5) == 0) {
        if (strlen(&CMD[5]) < 15) {
            strcpy(S.juiz, &CMD[5]);
        } else {
            goto ERR;
        }
#if 0
    } else if (strncmp_P(CMD, PSTR("+queda"), 6) == 0) {
        if (S.dts[S.hit] == HIT_MARK) {
            goto ERR;
        }
        while (1) {
            S.hit += 1;
            if (S.dts[S.hit]==HIT_MARK or S.dts[S.hit]==HIT_SERV) {
                break;
            }
        }
    } else if (strncmp_P(CMD, PSTR("-1"), 2) == 0) {
        if (S.hit > 0) {
            S.hit -= 1;
            if (S.dts[S.hit] == HIT_NONE) {
                S.hit -= 1;
            }
        } else {
            goto ERR;
        }
    } else if (strncmp_P(CMD, PSTR("+1"), 2) == 0) {
        if (S.dts[S.hit] != HIT_MARK) {
            S.hit += 1;
            if (S.dts[S.hit] == HIT_SERV) {
                S.hit += 1;    // skip HIT_NONE
            }
        } else {
            goto ERR;
        }
#endif
    } else {
        goto ERR;
    }
 
    if (0) {
ERR:;
        Serial.println(F("err"));
OK:;
    } else {
        Serial.println(F("ok"));
    }
    EEPROM_Save();
    PT_All();
    Serial_Score();
    TV_All("CMD", 0, 0, 0);
 
    return IN_NONE;
}
