# Commander

> 본 파일은 `<windows.h>`를 포함하고 있어, window 운영체제에서만 작동합니다.

> 고등학교 2학년 겨울방학 때 만들었으며 들여쓰기가 제대로 되어있지 않습니다.   
> 이 프로그램을 통해 사용자는 프로그램 안에서 간단한 코딩을 할 수 있습니다.

<hr/>

## 시작

> **commander.cpp**를 실행시켜 터미널에서 시작합니다. **(기본 설정에서 창크기가 작으면 제대로 작동하지 않으니 주의하세요.)**

<hr/>

## 화면

  - #### Commander
    이곳에 타자를 쳐 명령어를 입력합니다.
    `\`로 커서를 내리고, `|`로 커서를 올립니다.

    > 영어, 숫자 기호, `space bar`, `tab`, `enter`, `backspace`, `shift` 외의 다른 키를 입력하면 오류가 발생합니다.   
  - #### Help mesaage Running check
    **Commander**에 `/` 또는 `?`로 시작하여 명령어를 입력하면 레퍼런스를 보여줍니다.
    `Helping!`를 입력하면 사용법을 보여줍니다.

    코드가 실행 중일 때, 줄이 제대로 실행이 됐는지를 보여줍니다.
  - #### Bar
    > **Commander** 창일 때, `tab`을 눌러 전환할 수 있습니다.      
    > `w`, `a`, `s`, `d`로 클릭 커서를 움직이고 `q`를 눌러 선택합니다.   
    - **Run**   
      명령을 실행합니다.   
    - **Clear☜**   
      **Commander** 창을 초기화합니다.   
    - **Clear☞**   
      **Running display** 창을 초기화합니다.   
    - **setting**   
      커서를 커스터마이징합니다.   
    - **version**   
      업데이트된 내용과 버전을 확인합니다.   
    - **Length, Lines**   
      글자수와 줄개수를 확인합니다.   
    - *File, Comp, void*   
      > 미구현   
  - #### Running display
    코드 실행 결과를 확인할 수 있습니다.

    왼쪽 상단의 좌표가 (0,0) 입니다.
    상단에서는 행좌표를 확인할 수 있습니다.

<hr/>

## 문법

 ### 실행 명령어 (`/`)
  - #### /say   
    > **Running diplay**의 (0,0) 위치에 택스트를 생성합니다.

    ```c++
    /say "[TEXT]"
    ```
  - #### /tell   
    > **Running diplay**의 특정 위치에 문자열을 출력합니다.    

    ```c++
    /tell [XPOS] [YPOS] "[TEXT]" // 특정 위치에 출력
    /tell [XPOS] [YPOS] [TEXT-COLOR] [BACKGROUND-COLOR] "[TEXT]" //특정 위치에, 특정 색깔로 출력
    ```
  - #### /textlen     
    > 문자열의 길이를 변수에 대입합니다.

    ```c++
    /textlen "[TEXT]" [VARIABLE] //텍스트 길이를 변수에 대입
    /textlen [VARIABLE] // 최근에 사용한 텍스트 길이를 변수에 대입
    ```
  - #### /color
    > 앞으로의 색 설정을 변경합니다.
    > 다른 색 설정보다 우선순위가 낮습니다.

    ```c++
    /color [TEXT-COLOR] [BACKGROUND-COLOR]
    ```
  - #### /attr   
    > 최근에 생성한 도형 또는 택스트의 속성을 변경합니다.

      ```c++
      /attr move [XPOS] [YPOS]
      /attr copy [XPOS] [YPOS]
      /attr color [TEXT-COLOR] [BACKGROUND-COLOR]
      ```
  - #### /line   
    > **Running diplay** 화면에 선을 출력합니다.    

    ```c++
    /line [X-FROM] [Y-FROM] [X-TO] [Y-TO]  [BACKGROUND-COLOR]
    ```
  
  - #### /fill
    > **Running diplay**의 특정 범위를 채웁니다.
 
    ```c++
    /fill [X-FROM] [Y-FROM] [X-TO] [Y-TO] [BACKGROUND-COLOR]
    ```
    - 라인, 채우기
      ```c++
      /fill [X-FROM] [Y-FROM] [X-TO] [Y-TO] [BACKGROUND-COLOR] //내부를 채워서 출력
      /fill [X-FROM] [Y-FROM] [X-TO] [Y-TO] [BACKGROUND-COLOR] line(false) //내부를 채워서 출력
      /fill [X-FROM] [Y-FROM] [X-TO] [Y-TO] [BACKGROUND-COLOR] line(true) //내부는 검정으로 채워서 라인만 출력
      /fill [X-FROM] [Y-FROM] [X-TO] [Y-TO] [BACKGROUND-COLOR] line(true) empty(false) //내부는 검정으로 채워서 라인만 출력
      /fill [X-FROM] [Y-FROM] [X-TO] [Y-TO] [BACKGROUND-COLOR] line(true) empty(true) //내부는 비우고 라인만 출력
      ```
  - #### /shape   
    > **Running diplay**에 도형을 생성합니다.   
    > 모든 도형은 접하는 직사각형의 왼쪽 모서리 끝을 기준점으로 합니다.
    
    ```c++
    /shape square [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR]
    /shape triangle [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR]
    /shape circle [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR]
    ```
    - 라인, 채우기
      ```c++
      /shape square [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR] //내부를 채워서 출력
      /shape square [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR] line(false) //내부를 채워서 출력
      /shape square [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR] line(true) //내부는 검정으로 채워서 라인만 출력
      /shape square [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR] line(true) empty(false) //내부는 검정으로 채워서 라인만 출력
      /shape square [SCALE] [XPOS] [YPOS] [BACKGROUND-COLOR] line(true) empty(true) //내부는 비우고 라인만 출력
      ```
      > `triangle`, `circle`의 경우도 마찬가지
  - #### /remove   
    > **Running diplay** 화면을 지웁니다.

    ```c++
    /remove all //전체 지우기
    /remove part [X-FROM] [Y-FROM] [X-TO] [Y-TO] //범위 지우기
    ```
    
  - #### /stop   
    > 실행을 강제 종료합니다.

    ```c++
    /stop
    ```
  - #### /delay   
    > 실행을 지연합니다.

    ```c++
    /delay [TIME] //단위는 ms
    ```
  - #### /goto
    > **Commander**의 특정 줄번호로 이동합니다.
    
    ```c++
    /goto [LINE-POS]
    ```
  
  - #### /int   
    > 정수형 변수를 선언합니다.   
    > 선언한 변수는 항상 `[ ... ]` 사이에 변수명을 입력하여 사용합니다.   
    > 숫자처럼 사용할 수 있습니다.    
    > 문자열 안에서 또한 같은 방식으로 사용할 수 있습니다. (ex. `/tell [a] [a]+2 "a = [a]"`)   
    
    ```c++
    /int "[VARIABLE]" //선언과 함께 0 대입
    /int "[VARIABLE]" = [NUMBER] //선언과 함께 수 대입
    ```
  - #### /vc
    > 변수를 연산합니다.
    
    ```c++
    /vc [VARIABLE] = [NUMBER] //대입
    /vc [VARIABLE] += [NUMBER] //더하기
    /vc [VARIABLE] -= [NUMBER] //빼기
    /vc [VARIABLE] *= [NUMBER] //곱하기
    /vc [VARIABLE] /= [NUMBER] //나누기
    ```
  - #### /random   
    > 변수에 난수를 대입합니다.   
    
    ```c++
    /random [RAND-TO] [RAND-FROM] [VARIABLE]
    ```
  - #### /usef   
    > 미구현   
    > 함수를 사용합니다.
    
    ```c++
    /usef "[FUNC_NAME]" ([VARIABLES])
    ```
  - #### /deff   
    > 미구현   
    > 함수를 선언합니다.
    
    ```c++
    /deff "[FUNC_NAME]" ([VARIABLES]) {
    ```
  
### 감지 명령어 (`?`)
 
  - #### ?if
    > 그러한 경우를 감지합니다.

    ```c++
    ?if([CONDITONS]) {
    ```
  - #### ?unless
    > 그렇지 않은 경우를 감지합니다.

    ```c++
    ?unless([CONDITONS]) {
    ```
  - #### ?for
    > 특정 조건을 만족할 때 실행을 반복합니다.

    ```c++
    ?for([CONDITONS]) [REPEAT-COUNT] { //특정 횟수만큼 반복
    ?for([CONDITONS]) i { //무한 반복
    ```
    > 무한 반복 시에 실행을 빠져나올 수 없는 점에 주의하세요.   
  - #### ?test
    > 사용자의 키입력을 감지합니다.

    ```c++
    ?test('[CHARACTER]') { //특정 문자를 감지
    ?test(key) { //아무 문자나 감지
    ```

 ### 연산자
  > 연산의 결과는 숫자처럼 사용할 수 있습니다.   
  > (ex. `/tell 1*2 3+4^(3-2) "abc"`, `?if(123>=12&&10+1==9+8) {`)

  - #### +   
    > 두 피연산자를 더합니다.
  - #### -   
    > 두 피연산자를 뺍니다.
  - #### *   
    > 두 피연산자를 곱합니다.
  - #### /   
    > 두 피연산자를 나눕니다.
  - #### %   
    > 두 피연산자에 대해서 나머지를 구합니다.
  - #### ^   
    > 두 피연산자를 지수연산 합니다.
    
  - #### &&   
    > 두 피연산자를 논리곱 합니다.
  - #### \##   
    > 두 피연산자를 논리합 합니다.
  - #### <, <=, >, >, ==   
    > 두 피연산자를 비교합니다.

  - #### (, )   
    > 피연산자를 우선 연산합니다.

 ### 중괄호 (`}`)
   감지 명령어에서 사용한 열린 `{`를 닫습니다.

 ### 색 번호    
   > 명령어 입력 시에 `[TEXT-COLOR]`, `[BACKGROUND-COLOR]`에 사용됩니다.   

   | 색 | 번호 |
   | --- | --- |
   | 검정 | 0 |
   | 파랑 | 1 |
   | 초록 | 2 |
   | 청록 | 3 |
   | 빨강 | 4 |
   | 보라 | 5 |
   | 갈색 | 6 |
   | 밝은 회색 | 7 |
   | 짙은 회색 | 8 |
   | 하늘 | 9 |
   | 연두 | 10 |
   | 밝은 청록 | 11 |
   | 밝은 빨강 | 12 |
   | 밝은 보라 | 13 |
   | 노랑 | 14 |
   | 하양 | 15 |

<hr/>
















































 
