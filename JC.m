%JC法例子，Z=R-G-Q；R对数，G正太。Q极值

clear;
clc;
clear global variables;
muX = [22; 10; 2];
sigmaX = [2; 0.9; 0.6];
%对R当量正态化的参数
sLn = sqrt(log(1+sigmaX(1)/muX(1)^2));
mLn = log(muX(1)) - sLn^2 / 2;
%对极值Ⅰ行v分布进行当量正态化
aEv = sqrt(6) * sigmaX(3) / pi;
uEv = -psi(1) * aEv - muX(3);
%储存mu和sigma初值，防止被迭代
muX1 = muX;
sigmaX1 = sigmaX;
x = muX;
normX = eps; %(eps指代一个很小的浮点数精度值)
while abs(normX-norm(x)) / normX > 1e-6
    normX = norm(x); %计算新的x的范数，填入迭代指标
    muZ = x(1) - x(2) - x(3);
    gZ = [1, -1, -1]; %功能函数以及功能函数的梯度
    %对非正态分布的函数进行正态化
%     cdfX = [logncdf(x(1), mLn, sLn); normcdf(x(2), muX(2), sigmaX(2)); 1 - evcdf(-x(3), uEv, aEv)];
%     pdfX = [lognpdf(x(1), mLn, sLn); normpdf(x(2), muX(2), sigmaX(2)); evpdf(-x(3), uEv, aEv)];
    cdfX = [logncdf(x(1), mLn, sLn);  1 - evcdf(-x(3), uEv, aEv)];
    pdfX = [lognpdf(x(1), mLn, sLn);  evpdf(-x(3), uEv, aEv)];
    
    %计算标准差
    nc = norminv(cdfX);
    sigmaX1(1:2:3) = normpdf(nc) ./ pdfX;
    %计算mu
    muX1 = x(1:2:3) - nc * sigmaX1(1:2:3);
    gs = gZ .* sigmaX1;
    alphaX = -gs / norm(gs);
    %计算β
    beta = (muZ - alphaX' * (muX - x)) / norm(gs);
    %循环x
    x = muX + beta * sigmaX .* alphaX;
end