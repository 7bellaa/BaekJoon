# [Platinum II] A.I. War (Large) - 12490 

[문제 링크](https://www.acmicpc.net/problem/12490) 

### 성능 요약

메모리: 2960 KB, 시간: 340 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 그래프 이론, 그래프 탐색, 집합과 맵, 너비 우선 탐색, 비트마스킹, 최단 경로, 해시를 사용한 집합과 맵

### 제출 일자

2026년 3월 13일 02:42:49

### 문제 설명

<p>A.I. War is a real-time strategy game developed by Arcen Games. This problem was inspired by the game, but does not assume you have played it.</p>

<h3>Problem</h3>

<p>You're facing an artificial intelligence in a deadly war for the future of the galaxy. In order to defeat the A.I., you will need to threaten its <em>home planet</em>. Some planets are connected to each other by wormholes; any planet may be connected to any number of other planets using the wormholes.</p>

<p>You begin by owning only your home planet. Each turn, you may conquer any planet you <em>threaten</em>. You threaten a planet if you don't own it, and it is connected by a wormhole to any of the planets you own. Once you have conquered a planet, you own it. As soon as you threaten the A.I.'s home planet, you may not conquer any more planets.</p>

<p>While attending the most important day in tactical school, you discovered two things about the A.I.:</p>

<ul>
	<li>For each planet you conquer, the A.I. will become more powerful, because it will see you as a threat and produce more ships to defend itself.</li>
	<li>The A.I. will defend every planet you're currently threatening.</li>
</ul>

<p>You have combined those two facts to create a strategy:</p>

<ol>
	<li>You will conquer planets until you threaten the A.I.'s home base.</li>
	<li>If there are multiple ways of completing step 1, do it while conquering the <strong>smallest</strong>possible number of planets.</li>
	<li>If there are multiple ways of completing step 2, do it so that at the end you will threaten the <strong>largest</strong> possible number of planets.</li>
</ol>

<p>Given the planets and the wormholes, how many planets will you conquer and threaten on your way to the A.I.'s home base if you follow the strategy described above?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>.  <strong>T</strong> test cases follow. Each test case starts with a single line containing two space-separated integers: <strong>P</strong>, the number of planets, and <strong>W</strong>, the number of wormholes. Your home planet is planet 0, and the A.I.'s home planet is planet 1.</p>

<p>The second line of each test case will contain <strong>W</strong> space-separated pairs of comma-separated integers <strong>x</strong><sub>i</sub>,<strong>y</strong><sub>i</sub>. Each of these indicates that there is a two-way wormhole connecting planets <strong>x</strong><sub>i</sub> and <strong>y</strong><sub>i</sub>.</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 50.</li>
	<li>0 ≤ <strong>x</strong><sub>i</sub> < <strong>y</strong><sub>i</sub> < <strong>P</strong>.</li>
	<li>Each wormhole is unique: If i ≠ j, then (<strong>x</strong><sub>i</sub>, <strong>y</strong><sub>i</sub>) ≠ (<strong>x</strong><sub>j</sub>, <strong>y</strong><sub>j</sub>).</li>
	<li>There will be at least one way to reach the A.I.'s home planet from your home planet using a series of wormholes.</li>
	<li>2 ≤ <strong>P</strong> ≤ 400.</li>
	<li>1 ≤ <strong>W</strong> ≤ 2000.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: c t", where x is the case number (starting from 1), c is the number of planets you conquer if you follow the above strategy, and t is the number of planets you threaten at the end (including the A.I.'s home planet).</p>

